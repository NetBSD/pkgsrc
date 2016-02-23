# $NetBSD: Makefile,v 1.2 2016/02/23 20:18:12 bsiegert Exp $

DISTNAME=	go-crypto-0.0.20151215
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=	crypto
GITHUB_TAG=	f18420efc3b4f8e9f3d51f6bd2476e92c46260e9

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/golang/crypto/
COMMENT=	Go supplementary cryptography libraries
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	golang.org/x/crypto

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
