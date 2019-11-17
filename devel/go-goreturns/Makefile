# $NetBSD: Makefile,v 1.10.2.1 2019/11/17 08:30:08 spz Exp $

DISTNAME=	goreturns-0.0.20180301
PKGNAME=	go-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sqs/}
GITHUB_PROJECT=	goreturns
GITHUB_TAG=	83e02874ec120f73d5f7dd382d62449dc8abe9c6

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/sqs/goreturns
COMMENT=	Formatting tool filling in return statements with zero values
LICENSE=	modified-bsd

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/sqs/${GITHUB_PROJECT}

.include "../../devel/go-tools/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
