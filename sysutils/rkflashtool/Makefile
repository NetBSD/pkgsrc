# $NetBSD: Makefile,v 1.1 2015/10/24 21:46:07 tnn Exp $

DISTNAME=	rkflashtool-20151023
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=neo-technologies/}
GITHUB_PROJECT=	rkflashtool
GITHUB_TAG=	7b170ac73cabd4cc87b81c71c0aad9351e851d74

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/neo-technologies/rkflashtool/
COMMENT=	Tools for flashing Rockchip ARM devices
USE_TOOLS+=	pkg-config gmake
LICENSE=	2-clause-bsd

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
