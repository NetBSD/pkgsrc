# $NetBSD: Makefile,v 1.1.1.1 2007/10/17 21:35:53 agc Exp $

DISTNAME=	open-vm-tools-2007.09.04-56574
PKGNAME=	open-vm-tools-2007.09.04.56574
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=open-vm-tools/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://open-vm-tools.sourceforge.net/
COMMENT=	Open source VMware tools

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/guestd/guestd ${PREFIX}/sbin/vmware-guestd

.include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
