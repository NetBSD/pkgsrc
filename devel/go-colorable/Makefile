# $NetBSD: Makefile,v 1.9 2019/08/14 15:45:41 bsiegert Exp $

DISTNAME=	go-colorable-0.0.9
MASTER_SITES=	${MASTER_SITE_GITHUB:=mattn/}
PKGREVISION=	8
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/mattn/go-colorable
COMMENT=	Colorable writer for Windows
LICENSE=	mit

GO_DIST_BASE=	${PKGBASE}-${PKGVERSION_NOREV}
GO_SRCPATH=	${HOMEPAGE:S,https://,,}

.include "../../devel/go-isatty/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
