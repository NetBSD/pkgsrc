# $NetBSD: Makefile,v 1.1 2013/11/16 07:41:00 mef Exp $

PKG_VERSION=		3.4.6
# PKGNAME will have option name only when explictly selected
PKGNAME=		nios2-gcc3-${PKG_VERSION}
CATEGORIES=		cross
MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNU gcc for Altera FPGA Nios2 processor
LICENSE=		gnu-gpl-v2

MASTER_SITES=		ftp://ftp.altera.com/outgoing/download/support/ip/processors/nios2/gnu/
DISTNAME=		nios2_gnu_gcc3_10.0
#			nios2_gnu_gcc3_10.1.tgz are the exactly same, see MD5

EXTRACT_ELEMENTS=	gcc
WRKSRC=			${WRKDIR}/gcc
#PATH:=                  ${CROSSBASE}/bin:${PATH}

USE_TOOLS+=		gmake makeinfo perl
USE_GNU_CONFIGURE_HOST=	no
#BUILD_DEFS+=		CROSSBASE	#included in ../nios2/Makefile.common

DEPENDS+=		nios2-binutils220-[0-9]*:../../cross/nios2-binutils220

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

NIOS2_TARGET?=		nios2-elf
PLIST_SUBST+=		NIOS2_TARGET=${NIOS2_TARGET:Q}

USE_CROSSBASE=		yes
BUILD_DEFS+=		CROSSBASE
PATH:=			${CROSSBASE}/bin:${PATH}

BUILD_DEPENDS+=		gtexinfo-[0-9]*:../../devel/gtexinfo

.if defined(GNU_CONFIGURE)
CONFIGURE_ARGS=		# reset
CONFIGURE_ARGS+=	--target=${NIOS2_TARGET:Q}
# following line to avoid getting
#    make: exec(nios2--netbsdelf-ar) failed (No such file or directory)
USE_GNU_CONFIGURE_HOST= NO
.endif
CONFIGURE_ARGS+=	--enable-languages=c
CONFIGURE_ARGS+=	--disable-multilib
CONFIGURE_ARGS+=	--disable-threads
CONFIGURE_ARGS+=	--disable-nls
# to avoid strange problem due to long `uname -a` result
CONFIGURE_ARGS+=	--host=${MACHINE_ARCH}--${LOWER_OPSYS}
CONFIGURE_ARGS+=	--build=${MACHINE_ARCH}--${LOWER_OPSYS}

# pkglint flags, but seems necessary not generating dir file
INFO_FILES=		no

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
