# $NetBSD: Makefile,v 1.21 2020/07/13 19:45:45 alnsn Exp $

PKGNAME=	go-ed25519-20171601
PKGREVISION=	19
GITHUB_TAG=	5312a61534124124185d41f09206b9fef1d88403
DISTNAME=	ed25519-${GITHUB_TAG}
CATEGORIES=	devel security
MASTER_SITES=	${MASTER_SITE_GITHUB:=agl/}
GITHUB_PROJECT=	ed25519

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/agl/ed25519
COMMENT=	Ed25519 for Go
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	ed25519-${GITHUB_TAG}
GO_SRCPATH=	github.com/agl/ed25519

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
