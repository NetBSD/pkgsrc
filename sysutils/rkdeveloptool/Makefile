# $NetBSD: Makefile,v 1.3 2023/10/14 16:09:33 tnn Exp $

DISTNAME=	rkdeveloptool-1.32
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=rockchip-linux/}
GITHUB_TAG=	46bb4c073624226c3f05b37b9ecc50bbcf543f5a

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rockchip-linux/rkdeveloptool
COMMENT=	Rockchip RockUSB development tool
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS=	autoconf automake autoreconf gmake pkg-config
GNU_CONFIGURE=	yes

BUILDLINK_TRANSFORM+=	rm:-Werror

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
