# $NetBSD: Makefile,v 1.15 2012/10/02 20:11:34 asau Exp $
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

USE_TOOLS+=	pax

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty
RUN_LDCONFIG=		yes

INSTALLATION_DIRS=	bin include/Cg include/CgFX ${PKGMANDIR}/man3 \
			share/NVIDIA-Cg-linux share/doc/NVIDIA-Cg-linux \
			${EMULDIR}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/usr/bin/cgc ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/usr/include/Cg/* \
		${DESTDIR}${PREFIX}/include/Cg
	${INSTALL_DATA} ${WRKSRC}/usr/include/CgFX/* \
		${DESTDIR}${PREFIX}/include/CgFX
	${INSTALL_DATA} ${WRKSRC}/usr/lib/* ${DESTDIR}${EMULDIR}/lib
	${INSTALL_MAN} ${WRKSRC}/usr/share/man/man3/* \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
	cd ${WRKSRC}/usr/local && pax -rwppm . \
		${DESTDIR}${PREFIX}/share/NVIDIA-Cg-linux

.include "../../mk/bsd.pkg.mk"
