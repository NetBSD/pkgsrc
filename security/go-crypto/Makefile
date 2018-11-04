# $NetBSD: Makefile,v 1.16 2018/11/04 18:38:05 bsiegert Exp $

COMMENT=	Go supplementary cryptography libraries
PKGREVISION=	3
DISTNAME=	go-crypto-0.0.20180308
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=	crypto
GITHUB_TAG=	c7dcf104e3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/golang/crypto/
LICENSE=	modified-bsd

GO_SRCPATH=	golang.org/x/crypto
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*

CONFLICTS=	go-crypto-acme-[0-9]*

.include "../../lang/go/go-package.mk"
.include "../../devel/go-sys/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
