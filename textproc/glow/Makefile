# $NetBSD: Makefile,v 1.55.2.2 2026/11/11 20:32:21 maya Exp $

DISTNAME=	glow-2.1.2
PKGREVISION=	9
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
