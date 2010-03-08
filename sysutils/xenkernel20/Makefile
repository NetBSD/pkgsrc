# $NetBSD: Makefile,v 1.6 2010/03/08 01:19:42 jym Exp $
#

DISTNAME=	xen-2.0.7-install-x86_32
PKGNAME=	xenkernel20-2.0.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cl.cam.ac.uk/Research/SRG/netos/xen/downloads/
EXTRACT_SUFX=	.tgz

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=user-destdir

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/ports/xen/
COMMENT=	Xen Kernel

ONLY_FOR_PLATFORM=	Linux-2.[46]*-i386 NetBSD-*-i386

WRKSRC=		${WRKDIR}/xen-2.0-install

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/xen-kernel
	${INSTALL_DATA} ${WRKSRC}/install/boot/xen.gz \
			${DESTDIR}${PREFIX}/xen-kernel/xen.gz

.include "../../mk/bsd.pkg.mk"
