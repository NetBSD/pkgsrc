# $NetBSD: Makefile,v 1.75 2017/05/28 02:28:24 maya Exp $

DISTNAME=	binutils-2.26.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://directory.fsf.org/project/binutils/
COMMENT=	GNU binary utilities
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3
EXTRACT_SUFX=	.tar.bz2

# bfd.h used without depending on it
MAKE_JOBS_SAFE=	no

CONFLICTS=	avr-binutils<2.13.2.1nb1

USE_PKGLOCALEDIR=	yes
REPLACE_LOCALEDIR_PATTERNS+=	Make-in

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

# PR pkg/48504, ksh is sufficient for NetBSD 5.2 and NetBSD 6.1
.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MNetBSD-[5-6].*-*) && \
	empty(MACHINE_PLATFORM:MNetBSD-6.99.*-*)
USE_TOOLS+=		ksh
CONFIG_SHELL=		ksh
.endif

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-lib-path='/lib:/usr/lib'
CONFIGURE_ARGS+=	--program-prefix=g
BINUTILS_PREFIX=	${PREFIX}/${MACHINE_GNU_PLATFORM}

PLIST_SRC=	${PKGDIR}/PLIST.common
PLIST_SRC+=	${WRKDIR}/PLIST_DYNAMIC

INFO_FILES=	yes

INSTALLATION_DIRS=	${PKGGNUDIR}bin ${PKGGNUDIR}${PKGMANDIR}/man1

# gprof (XXX: and others?) cannot be built on all platforms
#
PLIST_VARS+=	gprof ld gold SunOS

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "IRIX" && ${OPSYS} != "AIX"
PLIST.gprof=	yes
EXTRA_FILES+=	gprof
.endif

.if ${OPSYS} != SunOS
PLIST.ld=	yes
EXTRA_FILES+=	ld
.endif

.if ${OPSYS} == SunOS
PLIST.SunOS=	yes
.endif

.if ${OPSYS} == DragonFly \
	|| (${OPSYS} == FreeBSD && empty(OS_VERSION:M[12345678].*)) \
	|| (${OPSYS} == OpenBSD && empty(OS_VERSION:M[1234].*)) \
	|| (${OPSYS} == NetBSD && empty(OS_VERSION:M[12345].*))
BUILD_GOLD=	yes
PLIST.gold=	yes
USE_TOOLS+=	bison
EXTRA_FILES+=	dwp ld.gold
CONFIGURE_ARGS+=--enable-gold --enable-plugins
.endif

CFLAGS.OpenBSD+=	-Wno-bounded

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-unused-value -Wno-format-security \
		-Wno-uninitialized -Wno-format -Wno-string-plus-int \
		-Wno-empty-body -Wno-self-assign -Wno-unused-function \
		-Wno-error=unused-const-variable
.endif

# Issue is fixed in upstream binutils, remove this when upgraded past 2.24
.if !empty(CC_VERSION:Mgcc-4.9.*)
CONFIGURE_ARGS+=	--disable-werror
.endif

# Prevent the need to run texi2pod.pl and pod2man which would
# require perl as a build dependency.
post-configure:
.for f in ld/ldver.texi ld/ld.1 gas/doc/gasver.texi gas/doc/as.1
	set -e; \
	if [ -f ${WRKSRC}/${f} ]; then					\
		${TOUCH} ${WRKSRC}/${f};				\
	fi
.endfor

SYMLINK_FILES =	addr2line ar as c++filt dlltool elfedit ld.bfd		\
		nlmconv nm objcopy objdump ranlib readelf size strings	\
		strip windmc windres
.if defined(PLIST.gprof)
SYMLINK_FILES+=	gprof
.endif
.if defined(PLIST.ld)
SYMLINK_FILES+=	ld
.endif
.if defined(BUILD_GOLD)
SYMLINK_FILES+=	ld.gold dwp
.endif

post-install:
	cd ${DESTDIR}${PREFIX} &&					\
	    find ${MACHINE_GNU_PLATFORM}/lib/ldscripts -type f -print	\
	    | sort -r							\
	    > ${WRKDIR}/PLIST_DYNAMIC
.for f in ${SYMLINK_FILES}
	set -e; \
	if [ -f ${DESTDIR}${PREFIX}/bin/g${f:Q} ]; then \
	    ${LN} -sf ${PREFIX}/bin/g${f} ${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/${f}; \
	fi
	if [ -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/g${f:Q}.1 ]; then \
	    ${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/g${f}.1 \
	              ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man1/${f}.1; \
	fi
.endfor

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
