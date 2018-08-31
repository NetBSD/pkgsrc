# $NetBSD: Makefile,v 1.1 2018/08/31 10:09:51 tnn Exp $

GITHUB_TAG=	081d237ad5bf8f03170c9d60bd94ceefa0352aaf
DISTNAME=	rkdeveloptool-1.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=rockchip-linux/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rockchip-linux/rkdeveloptool
COMMENT=	Rockchip RockUSB development tool
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS=	autoconf automake autoreconf gmake pkg-config
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
