# $NetBSD: Makefile,v 1.1.1.1 2005/10/13 20:58:20 agc Exp $
#

DISTNAME=	xen-2.0.7-install-x86_32
PKGNAME=	xenkernel20-2.0.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cl.cam.ac.uk/Research/SRG/netos/xen/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.netbsd.org/Ports/xen/
COMMENT=	Xen Kernel

WRKSRC=		${WRKDIR}/xen-2.0-install

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/xen-kernel
	${INSTALL_DATA} ${WRKSRC}/install/boot/xen.gz ${PREFIX}/xen-kernel/xen.gz

.include "../../mk/bsd.pkg.mk"
