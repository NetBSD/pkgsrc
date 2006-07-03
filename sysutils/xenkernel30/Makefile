# $NetBSD: Makefile,v 1.1.1.1 2006/07/03 07:28:22 agc Exp $
#

DISTNAME=	xen-3.0.2-2-install-x86_32
PKGNAME=	xenkernel30-3.0.2.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cl.cam.ac.uk/Research/SRG/netos/xen/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.netbsd.org/Ports/xen/
COMMENT=	Xen3 Kernel

WRKSRC=		${WRKDIR}/xen-3.0.2-2-install

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/xen3-kernel
	${INSTALL_DATA} ${WRKSRC}/install/boot/xen.gz ${PREFIX}/xen3-kernel/xen.gz

.include "../../mk/bsd.pkg.mk"
