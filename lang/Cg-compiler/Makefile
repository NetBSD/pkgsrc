# $NetBSD: Makefile,v 1.11 2007/08/23 18:20:31 jlam Exp $
#

DISTNAME=	CgLinux-1.3.0408-0400
PKGNAME=	Cg-compiler-1.3beta2
PKGREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	ftp://download.nvidia.com/developer/cg/Cg_1.3/Linux/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://developer.nvidia.com/object/cg_toolkit.html
COMMENT=	NVIDIA Cg Compiler for Linux

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base
EMUL_REQD=		suse>=7.3

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty
RUN_LDCONFIG=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man3 share

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/Cg
	${INSTALL_DATA_DIR} ${PREFIX}/include/CgFX
	${INSTALL_DATA_DIR} ${PREFIX}/share/NVIDIA-Cg-linux
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/NVIDIA-Cg-linux
	${INSTALL_PROGRAM} ${WRKSRC}/usr/bin/cgc ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/usr/include/Cg/* ${PREFIX}/include/Cg
	${INSTALL_DATA} ${WRKSRC}/usr/include/CgFX/* ${PREFIX}/include/CgFX
	${INSTALL_DATA} ${WRKSRC}/usr/lib/* ${EMULDIR}/lib
	${INSTALL_MAN} ${WRKSRC}/usr/share/man/man3/* ${PREFIX}/${PKGMANDIR}/man3
	cd ${WRKSRC}/usr/local && ${PAX} -rwppm . ${PREFIX}/share/NVIDIA-Cg-linux

.include "../../mk/bsd.pkg.mk"
