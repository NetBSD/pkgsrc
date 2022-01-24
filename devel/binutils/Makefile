# $NetBSD: Makefile,v 1.102 2022/01/24 15:10:46 fcambus Exp $

DISTNAME=	binutils-2.37
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/binutils/
COMMENT=	GNU binary utilities
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

CONFLICTS=	avr-binutils<2.13.2.1nb1

USE_PKGLOCALEDIR=		yes
REPLACE_LOCALEDIR_PATTERNS+=	Make-in

USE_LANGUAGES=		c99 c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

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
TEST_TARGET=	check

TEST_DEPENDS+=	dejagnu-[0-9]*:../../devel/dejagnu

INSTALLATION_DIRS=	${PKGGNUDIR}bin ${PKGGNUDIR}${PKGMANDIR}/man1

#
# Supported utils and libraries differ quite a bit across platforms.
#
PLIST_VARS+=	ctf gas gold gprof ld

.include "../../mk/bsd.prefs.mk"

#
# libctf does not build on thes platforms at present.
#
.if ${OPSYS} == "Darwin" || ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--disable-libctf
.else
PLIST.ctf=		yes
.endif

.if ${OPSYS} != "Darwin"
PLIST.gas=	yes
.endif

.if ${OPSYS} != "IRIX" && ${OPSYS} != "AIX" && ${OPSYS} != "Darwin"
PLIST.gprof=	yes
.endif

#
# The PLIST.ld variable controls whether we install "ld -> gld" symlinks.  They
# are excluded on SunOS to avoid accidentally using the wrong "ld", and on
# Darwin as ld/gas are not built.
#
.if ${OPSYS} != SunOS && ${OPSYS} != "Darwin"
PLIST.ld=	yes
.endif

.if ${OPSYS} == DragonFly \
	|| (${OPSYS} == FreeBSD && empty(OS_VERSION:M[12345678].*)) \
	|| (${OPSYS} == OpenBSD && empty(OS_VERSION:M[1234].*)) \
	|| (${OPSYS} == NetBSD && empty(OS_VERSION:M[12345].*)) \
	|| ${OPSYS} == Linux
PLIST.gold=		yes
USE_TOOLS+=		bison
CONFIGURE_ARGS+=	--enable-gold --enable-plugins
.endif

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-unused-value -Wno-format-security \
		-Wno-uninitialized -Wno-format -Wno-string-plus-int \
		-Wno-empty-body -Wno-self-assign -Wno-unused-function \
		-Wno-error=unused-const-variable
.endif

.include "options.mk"

SYMLINK_FILES=	addr2line ar ${PLIST.gas:Das} c++filt dlltool elfedit \
		${PLIST.gprof:Dgprof} ${PLIST.ld:Dld} ${PLIST.gld:Dld.bfd} \
		${PLIST.gold:Dld.gold dwp} nlmconv nm objcopy objdump \
		ranlib readelf size strings strip windmc windres

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
