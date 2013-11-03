# $NetBSD: Makefile,v 1.1 2013/11/03 10:16:03 mef Exp $

PKG_VERSION=		3.4.6
# PKGNAME will have option name only when explictly selected
PKGNAME=		nios2-gcc-${PKG_VERSION}
CATEGORIES=		cross
MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNU gcc for Altera FPGA Nios2 processor
LICENSE=		gnu-gpl-v2

EXTRACT_ELEMENTS=	gcc
WRKSRC=			${WRKDIR}/gcc
PATH:=                  ${CROSSBASE}/bin:${PATH}

USE_TOOLS+=		gmake makeinfo perl
USE_GNU_CONFIGURE_HOST=	no
#BUILD_DEFS+=		CROSSBASE	#included in ../nios2/Makefile.common

DEPENDS+=		nios2-binutils-[0-9]*:../../cross/nios2-binutils

.include		"../../cross/nios2/Makefile.common"

CONFIGURE_ARGS+=	--enable-languages=c
CONFIGURE_ARGS+=	--disable-multilib
CONFIGURE_ARGS+=	--disable-threads
CONFIGURE_ARGS+=	--disable-nls
# to avoid strange problem due to long `uname -a` result
CONFIGURE_ARGS+=	--host=${MACHINE_ARCH}--${LOWER_OPSYS}
CONFIGURE_ARGS+=	--build=${MACHINE_ARCH}--${LOWER_OPSYS}

# pkglint flags, but seems necessary not generating dir file
INFO_FILES=		no

#.include "../../devel/gmp/buildlink3.mk"  # 4.4 or later
#.include "../../math/mpfr/buildlink3.mk"  # 4.4 or later

# to avoid conflict with binutils (to be fixed by more sophisticated way)
post-install:
	${RM}  ${DESTDIR}${CROSSBASE}/lib/libiberty.a
#  to avoid conflict wit mingw-w64-gcc-4.5.1
	${RM}  ${DESTDIR}${CROSSBASE}/man/man7/fsf-funding.7
	${RM}  ${DESTDIR}${CROSSBASE}/man/man7/gfdl.7
	${RM}  ${DESTDIR}${CROSSBASE}/man/man7/gpl.7
	${RM}  ${DESTDIR}${CROSSBASE}/info/cpp.info
	${RM}  ${DESTDIR}${CROSSBASE}/info/cppinternals.info
	${RM}  ${DESTDIR}${CROSSBASE}/info/gcc.info
	${RM}  ${DESTDIR}${CROSSBASE}/info/gccinstall.info
	${RM}  ${DESTDIR}${CROSSBASE}/info/gccint.info

.include "../../mk/bsd.pkg.mk"
