# $NetBSD: Makefile,v 1.22 2020/11/08 21:59:33 bsiegert Exp $

DISTNAME=	goreman-0.1.1
PKGNAME=	go-${DISTNAME}
PKGREVISION=	21
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=mattn/}
GITHUB_PROJECT=	goreman
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/mattn/goreman
COMMENT=	Foreman clone written in Go language
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/mattn/goreman

GO_BUILD_PATTERN=	${GO_SRCPATH}

.include "../../devel/go-colortext/buildlink3.mk"
.include "../../devel/go-godotenv/buildlink3.mk"
.include "../../devel/go-yaml/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
