# $NetBSD: Makefile,v 1.50.2.1 2026/07/14 00:36:07 maya Exp $

DISTNAME=	glow-2.1.2
PKGREVISION=	3
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
