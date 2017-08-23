# $NetBSD: Makefile,v 1.4 2017/08/23 13:57:30 jmcneill Exp $
#

VERSION=	20170823
DISTNAME=	sunxi-tools-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=linux-sunxi/}
GITHUB_PROJECT=	sunxi-tools
GITHUB_TAG=	cd9e6099e8668f4aa25d3ffc71283c0b138af1b7

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://linux-sunxi.org/
COMMENT=	Tools to help hacking Allwinner A10 (and successors) devices
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config

INSTALLATION_DIRS=	bin

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
