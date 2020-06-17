# $NetBSD: Makefile,v 1.8 2020/06/17 09:54:09 bsiegert Exp $

GITHUB_PROJECT=	jwt-go
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	v3.2.0
PKGNAME=	go-${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=dgrijalva/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/dgrijalva/jwt-go/
COMMENT=	Golang implementation of JSON Web Token
LICENSE=	mit

GO_SRCPATH=	github.com/dgrijalva/jwt-go
GO_DIST_BASE=	jwt-go-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
