# $NetBSD: Makefile,v 1.3 2006/10/19 22:50:25 bouyer Exp $
#

DISTNAME=	xen-3.0.3_0-install-x86_32
PKGNAME=	xenkernel30-3.0.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cl.cam.ac.uk/Research/SRG/netos/xen/downloads/ \
		http://bits.xensource.com/oss-xen/release/3.0.3-0/bin.tgz/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/Ports/xen/
COMMENT=	Xen3 Kernel

WRKSRC=		${WRKDIR}/dist

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/xen3-kernel
	${INSTALL_DATA} ${WRKSRC}/install/boot/xen.gz ${PREFIX}/xen3-kernel/xen.gz

.include "../../mk/bsd.pkg.mk"
