# $NetBSD: Makefile,v 1.8 2017/03/20 12:23:53 wiz Exp $

DISTNAME=	go-crypto-0.0.20170317
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=	crypto
GITHUB_TAG=	728b753

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/golang/crypto/
COMMENT=	Go supplementary cryptography libraries
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*
GO_SRCPATH=	golang.org/x/crypto

BROKEN=		Depends on go-net, which depends on this package.

#.include "../../net/go-net/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
