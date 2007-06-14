# $NetBSD: Makefile,v 1.1.1.1 2007/06/14 19:37:00 bouyer Exp $
#

VERSION=	3.1.0
DISTNAME=	xen-${VERSION}-install-x86_32
PKGNAME=	xenkernel3-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cl.cam.ac.uk/Research/SRG/netos/xen/downloads/ \
		http://bits.xensource.com/oss-xen/release/${VERSION}/bin.tgz/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/Ports/xen/
COMMENT=	Xen3 Kernel
CONFLICTS=	xenkernel30-*

WRKSRC=		${WRKDIR}/dist

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/xen3-kernel
	${INSTALL_DATA} ${WRKSRC}/install/boot/xen.gz ${PREFIX}/xen3-kernel/xen.gz

.include "../../mk/bsd.pkg.mk"
