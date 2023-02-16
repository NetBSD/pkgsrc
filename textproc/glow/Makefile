# $NetBSD: Makefile,v 1.13 2023/02/16 15:01:58 bsiegert Exp $

DISTNAME=	glow-1.5.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=charmbracelet/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://github.com/charmbracelet/glow
COMMENT=	Render markdown on the CLI
LICENSE=	mit

GO_BUILD_PATTERN=

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
