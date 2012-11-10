# $NetBSD: Makefile,v 1.4 2012/11/10 20:53:43 pettai Exp $
#

DISTNAME=	ykpers-1.8.2
CATEGORIES=	security
MASTER_SITES=	http://yubikey-personalization.googlecode.com/files/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://code.google.com/p/yubikey-personalization/
COMMENT=	Yubico's YubiKey re-programming toolkit
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	ykpers-1.pc.in

.include "../../security/libyubikey/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
