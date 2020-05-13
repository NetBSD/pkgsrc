# $NetBSD: Makefile,v 1.83 2020/05/13 03:32:38 rillig Exp $

DISTNAME=	binutils-2.34
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/binutils/
COMMENT=	GNU binary utilities
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

CONFLICTS=	avr-binutils<2.13.2.1nb1

USE_PKGLOCALEDIR=		yes
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

TOOLS_BROKEN+=		perl
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no
# Standard lib dirs on RHEL are named *lib64
LIB_PATH=		/lib:/usr/lib
.if exists(/usr/lib64)
LIB_PATH:=		/usr/lib64:${LIB_PATH}
.endif
.if exists(/lib64)
LIB_PATH:=		/lib64:${LIB_PATH}
.endif
CONFIGURE_ARGS+=	--with-lib-path=${LIB_PATH}
CONFIGURE_ARGS+=	--program-prefix=g
BINUTILS_PREFIX=	${PREFIX}/${MACHINE_GNU_PLATFORM}

PLIST_SRC=	${PKGDIR}/PLIST.common
PLIST_SRC+=	${WRKDIR}/PLIST_DYNAMIC

INFO_FILES=	yes

INSTALLATION_DIRS=	${PKGGNUDIR}bin ${PKGGNUDIR}${PKGMANDIR}/man1

# gprof (XXX: and others?) cannot be built on all platforms
#
PLIST_VARS+=	gprof ld gold SunOS CTF

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "IRIX" && ${OPSYS} != "AIX"
PLIST.gprof=	yes
.endif

.if ${OPSYS} != SunOS
PLIST.ld=	yes
.endif

.if ${OPSYS} == SunOS
PLIST.SunOS=	yes
.endif

# Temporary: libctf should be mature on Linux in the near future
.if ${OPSYS} != Linux
PLIST.CTF=	yes
.endif

.if ${OPSYS} == DragonFly \
	|| (${OPSYS} == FreeBSD && empty(OS_VERSION:M[12345678].*)) \
	|| (${OPSYS} == OpenBSD && empty(OS_VERSION:M[1234].*)) \
	|| (${OPSYS} == NetBSD && empty(OS_VERSION:M[12345].*))
BUILD_GOLD=		yes
PLIST.gold=		yes
USE_TOOLS+=		bison
CONFIGURE_ARGS+=	--enable-gold --enable-plugins
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

SYMLINK_FILES=	addr2line ar as c++filt dlltool elfedit ld.bfd		\
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
