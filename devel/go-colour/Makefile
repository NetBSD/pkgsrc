# $NetBSD: Makefile,v 1.14 2020/03/21 16:57:09 bsiegert Exp $

DISTNAME=	colour-0.0.0.20160524
PKGNAME=	go-${DISTNAME}
PKGREVISION=	13
MASTER_SITES=	${MASTER_SITE_GITHUB:=alecthomas/}
CATEGORIES=	devel
GITHUB_PROJECT=	colour
GITHUB_TAG=	60882d9e27213e8552dcff6328914fe4c2b44bc9

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alecthomas/colour
COMMENT=	Colour terminal text for Go
LICENSE=	mit

GO_DIST_BASE=	colour-${GITHUB_TAG}
GO_SRCPATH=	github.com/alecthomas/colour

.include "../../devel/go-isatty/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
