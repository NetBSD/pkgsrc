# $NetBSD: Makefile,v 1.2 2020/06/17 09:54:08 bsiegert Exp $

DISTNAME=	tmc-0.5.1
PKGNAME=	go-${DISTNAME}
PKGREVISION=	1
MASTER_SITES=	${MASTER_SITE_GITHUB:=bep/}
CATEGORIES=	devel
GITHUB_PROJECT=	tmc
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/bep/tmc/
COMMENT=	Codec for a Typed Map in Go
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/bep/tmc

USE_LANGUAGES=	# none

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
