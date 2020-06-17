# $NetBSD: Makefile,v 1.17 2020/06/17 09:54:17 bsiegert Exp $

DISTNAME=	smartcrop-0.2.0.20180227
PKGNAME=	go-${DISTNAME}
PKGREVISION=	16
MASTER_SITES=	${MASTER_SITE_GITHUB:=muesli/}
CATEGORIES=	graphics
GITHUB_PROJECT=	${PKGBASE:S/^go-//}
GITHUB_TAG=	f6ebaa786a12a0fdb2d7c6dee72808e68c296464

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/muesli/smartcrop
COMMENT=	Tool to find good image crops for arbitrary crop sizes
LICENSE=	mit

GO_DIST_BASE=	${PKGBASE:S/go-//}-${GITHUB_TAG}
GO_SRCPATH=	${HOMEPAGE:S,https://,,}

.include "../../graphics/go-image/buildlink3.mk"
.include "../../graphics/go-resize/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
