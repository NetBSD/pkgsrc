# $NetBSD: Makefile,v 1.2 2018/03/17 10:02:58 tnn Exp $

DISTNAME=	rkflashtool-20160324
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=neo-technologies/}
GITHUB_PROJECT=	rkflashtool
GITHUB_TAG=	094bd6410cb016e487e2ccb1050c59eeac2e6dd1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/neo-technologies/rkflashtool/
COMMENT=	Tools for flashing Rockchip ARM devices
USE_TOOLS+=	pkg-config gmake
LICENSE=	2-clause-bsd

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
