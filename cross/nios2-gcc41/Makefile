# $NetBSD: Makefile,v 1.8 2018/08/22 09:43:11 wiz Exp $

DISTNAME=		nios2_gnu_gcc4_13.0
PKG_VERSION=		4.1.2
PKGNAME=		nios2-gcc41-${PKG_VERSION}
PKGREVISION=		5
CATEGORIES=		cross
MASTER_SITES=		ftp://ftp.altera.com/outgoing/download/support/ip/processors/nios2/gnu/
EXTRACT_SUFX=		.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNU gcc 4.1 for Altera FPGA Nios2 processor
LICENSE=		gnu-gpl-v2

DEPENDS+=		nios2-binutils-[0-9]*:../../cross/nios2-binutils
BUILD_DEPENDS+=		gtexinfo-[0-9]*:../../devel/gtexinfo

GNU_CONFIGURE=		yes
INFO_FILES=		no
EXTRACT_ELEMENTS=	gcc-4.1
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}
PATH:=                  ${PREFIX}/cross/bin:${PATH}
GNU_CONFIGURE_PREFIX=	${PREFIX}/cross
USE_TOOLS+=		gmake makeinfo perl bison tar
# following line to avoid getting
#    make: exec(nios2--netbsdelf-ar) failed (No such file or directory)
USE_GNU_CONFIGURE_HOST= NO

NIOS2_TARGET?=		nios2-elf

CONFIGURE_ARGS=		# reset
CONFIGURE_ARGS+=	--target=${NIOS2_TARGET:Q}
CONFIGURE_ARGS+=	--enable-languages=c
CONFIGURE_ARGS+=	--disable-multilib
CONFIGURE_ARGS+=	--disable-threads
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-libssp
# to avoid strange problem due to long `uname -a` result
CONFIGURE_ARGS+=	--host=${MACHINE_ARCH}--${LOWER_OPSYS}
CONFIGURE_ARGS+=	--build=${MACHINE_ARCH}--${LOWER_OPSYS}
CFLAGS+=		-g

PLIST_SUBST+=		NIOS2_TARGET=${NIOS2_TARGET:Q}
PLIST_VARS+=		doc
.include "options.mk"

do-extract:
	(cd ${WRKDIR}; tar zxf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${EXTRACT_ELEMENTS} )

# to avoid conflict with binutils (to be fixed by more sophisticated way)
post-install:
	${RM}  ${DESTDIR}${PREFIX}/cross/lib/libiberty.a
#  to avoid conflict wit mingw-w64-gcc-4.5.1
	${RM}  ${DESTDIR}${PREFIX}/cross/man/man7/fsf-funding.7
	${RM}  ${DESTDIR}${PREFIX}/cross/man/man7/gfdl.7
	${RM}  ${DESTDIR}${PREFIX}/cross/man/man7/gpl.7
	${RM}  ${DESTDIR}${PREFIX}/cross/info/cpp.info
	${RM}  ${DESTDIR}${PREFIX}/cross/info/cppinternals.info
	${RM}  ${DESTDIR}${PREFIX}/cross/info/gcc.info
	${RM}  ${DESTDIR}${PREFIX}/cross/info/gccinstall.info
	${RM}  ${DESTDIR}${PREFIX}/cross/info/gccint.info

.include "../../mk/bsd.pkg.mk"
