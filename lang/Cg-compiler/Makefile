# $NetBSD: Makefile,v 1.5 2005/06/16 06:57:59 jlam Exp $
#

DISTNAME=	CgLinux-1.3.0408-0400
PKGNAME=	Cg-compiler-1.3beta2
CATEGORIES=	lang
MASTER_SITES=	ftp://download.nvidia.com/developer/cg/Cg_1.3/Linux/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://developer.nvidia.com/object/cg_toolkit.html
COMMENT=	NVIDIA Cg Compiler for Linux

ONLY_FOR_PLATFORM=  *-*-i386

WRKSRC=		${WRKDIR}
CHECK_SHLIBS=	no
NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
DEPENDS+=	suse_base>=7.3:../../emulators/suse_base
.endif

INSTALLATION_DIRS=	bin lib man/man3 share

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/Cg
	${INSTALL_DATA_DIR} ${PREFIX}/include/CgFX
	${INSTALL_DATA_DIR} ${PREFIX}/share/NVIDIA-Cg-linux
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/NVIDIA-Cg-linux
	${INSTALL_PROGRAM} ${WRKSRC}/usr/bin/cgc ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/usr/include/Cg/* ${PREFIX}/include/Cg
	${INSTALL_DATA} ${WRKSRC}/usr/include/CgFX/* ${PREFIX}/include/CgFX
	${INSTALL_DATA} ${WRKSRC}/usr/lib/* ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/usr/share/man/man3/* ${PREFIX}/man/man3
	cd ${WRKSRC}/usr/local && ${PAX} -rwppm . ${PREFIX}/share/NVIDIA-Cg-linux

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
