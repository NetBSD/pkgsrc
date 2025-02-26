# $NetBSD: Makefile,v 1.33 2025/02/26 01:20:20 schmonz Exp $

DISTNAME=	glow-2.0.0
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
