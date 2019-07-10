# $NetBSD: Makefile,v 1.15 2019/07/10 17:53:38 sevan Exp $
#

DISTNAME=	ykpers-1.16.1
CATEGORIES=	security
MASTER_SITES=	http://yubico.github.io/yubikey-personalization/releases/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://yubico.github.io/yubikey-personalization/
COMMENT=	Yubico's YubiKey re-programming toolkit
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes
USE_FEATURES+=	strnlen

PKGCONFIG_OVERRIDE+=	ykpers-1.pc.in

.include "../../security/libyubikey/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
