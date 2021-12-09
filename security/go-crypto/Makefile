# $NetBSD: Makefile,v 1.46 2021/12/09 17:50:13 bsiegert Exp $

COMMENT=	Go supplementary cryptography libraries
DISTNAME=	go-crypto-0.0.20200122
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=	crypto
GITHUB_TAG=	69ecbb4d6d

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/golang/crypto/
LICENSE=	modified-bsd
PKGREVISION=	15

GO_SRCPATH=	golang.org/x/crypto
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*

pre-patch:
	${RM} -rf ${WRKSRC}/acme

.include "../../lang/go/go-package.mk"
.include "../../devel/go-sys/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
