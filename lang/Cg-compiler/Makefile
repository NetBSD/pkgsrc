# $NetBSD: Makefile,v 1.1.1.1 2004/08/18 21:12:50 minskim Exp $
#

DISTNAME=	Cg-${DIST_VER}-Linux
PKGNAME=	Cg-compiler-${DIST_VER}
CATEGORIES=	lang
MASTER_SITES=	ftp://download.nvidia.com/developer/cg/Cg_1.2.1/Linux/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://developer.nvidia.com/object/cg_toolkit.html
COMMENT=	NVIDIA Cg Compiler for Linux

ONLY_FOR_PLATFORM=  *-*-i386

WRKSRC=		${WRKDIR}
CHECK_SHLIBS=	no
NO_BUILD=	yes
NO_BUILDLINK=	yes

DIST_VER=	1.2.1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
DEPENDS+=	suse_base>=7.3:../../emulators/suse_base
.endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/Cg
	${INSTALL_DATA_DIR} ${PREFIX}/include/CgFX
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/NVIDIA-Cg-linux
	${INSTALL_PROGRAM} ${WRKSRC}/usr/bin/cgc ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/usr/include/Cg/* ${PREFIX}/include/Cg
	${INSTALL_DATA} ${WRKSRC}/usr/include/CgFX/* ${PREFIX}/include/CgFX
	${INSTALL_DATA} ${WRKSRC}/usr/lib/* ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/usr/share/man/man3/* ${PREFIX}/man/man3
	cd ${WRKSRC}/usr/local && ${PAX} -rwppm . ${PREFIX}/share/NVIDIA-Cg-linux

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
