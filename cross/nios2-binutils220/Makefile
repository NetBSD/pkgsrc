# $NetBSD: Makefile,v 1.1 2013/11/16 07:41:00 mef Exp $

PKG_VERSION=		2.20
PKGNAME=		nios2-binutils220-${PKG_VERSION}
CATEGORIES=		cross
MASTER_SITES=		ftp://ftp.altera.com/outgoing/download/support/ip/processors/nios2/gnu/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNU binutils for Altera FPGA Nios2 processor
LICENSE=		gnu-gpl-v2

EXTRACT_ELEMENTS=	binutils-${PKGVERSION}
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

USE_TOOLS+=		gmake makeinfo perl tar
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
BUILD_DEFS+=		${NIOS_INFO_DIR}
INFO_FILES=		yes

.include		"../../cross/nios2/Makefile.common"

CONFIGURE_ARGS+=	--disable-nls
# install libiberty by architecture
CONFIGURE_ARGS+=	--libdir=${PREFIX}/${NIOS2_TARGET}/lib

# To avoid conflict with other cross/native info files,
NIOS_INFO_DIR=		${PREFIX}/info/${NIOS2_TARGET}
.include "../../mk/bsd.prefs.mk"
INFO_DIR?=		${NIOS_INFO_DIR}

# CONFIGURE_ARGS+=	--infodir=
#  doesn't make it, will be overridden by following variables
#  see mk/configure/gnu-configure.mk
GNU_CONFIGURE_INFODIR=	${NIOS_INFO_DIR}

do-extract:
	(cd ${WRKDIR}; tar zxf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${EXTRACT_ELEMENTS} )

# following file installed is reference only, not used at all for the moment
post-install:
	${INSTALL_DATA} files/nios2elf-netbsd.x ${DESTDIR}${PREFIX}/${NIOS2_TARGET}/lib/ldscripts

.include "../../mk/bsd.pkg.mk"
