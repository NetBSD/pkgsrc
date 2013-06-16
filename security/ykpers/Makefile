# $NetBSD: Makefile,v 1.7 2013/06/16 09:39:07 pettai Exp $
#

DISTNAME=	ykpers-1.13.0
CATEGORIES=	security
MASTER_SITES=	http://yubico.github.io/yubikey-personalization/releases/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://yubico.github.io/yubikey-personalization/
COMMENT=	Yubico's YubiKey re-programming toolkit
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	ykpers-1.pc.in

.include "../../security/libyubikey/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
