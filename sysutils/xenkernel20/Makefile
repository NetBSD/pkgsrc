# $NetBSD: Makefile,v 1.3 2006/07/06 21:14:19 jlam Exp $
#

DISTNAME=	xen-2.0.7-install-x86_32
PKGNAME=	xenkernel20-2.0.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cl.cam.ac.uk/Research/SRG/netos/xen/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/Ports/xen/
COMMENT=	Xen Kernel

WRKSRC=		${WRKDIR}/xen-2.0-install

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/xen-kernel
	${INSTALL_DATA} ${WRKSRC}/install/boot/xen.gz ${PREFIX}/xen-kernel/xen.gz

.include "../../mk/bsd.pkg.mk"
