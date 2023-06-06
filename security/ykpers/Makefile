# $NetBSD: Makefile,v 1.18 2023/06/06 12:42:17 riastradh Exp $
#

GITHUB_PROJECT=	yubikey-personalization
DISTNAME=	ykpers-1.20.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=Yubico/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/yubikey-personalization/
COMMENT=	Yubico's YubiKey re-programming toolkit
LICENSE=	modified-bsd

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config autoconf automake autoreconf
USE_LIBTOOL=	yes
USE_FEATURES+=	strnlen

PKGCONFIG_OVERRIDE+=	ykpers-1.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -if

.include "../../security/libyubikey/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
