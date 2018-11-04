# $NetBSD: Makefile,v 1.2 2018/11/04 18:38:02 bsiegert Exp $

DISTNAME=	go-colorable-0.0.9
MASTER_SITES=	${MASTER_SITE_GITHUB:=mattn/}
PKGREVISION=	1
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
