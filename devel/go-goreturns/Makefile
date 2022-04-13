# $NetBSD: Makefile,v 1.38 2022/04/13 07:51:02 bsiegert Exp $

DISTNAME=	goreturns-0.0.20180301
PKGNAME=	go-${DISTNAME}
PKGREVISION=	37
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sqs/}
GITHUB_PROJECT=	goreturns
GITHUB_TAG=	83e02874ec120f73d5f7dd382d62449dc8abe9c6

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/sqs/goreturns
COMMENT=	Formatting tool filling in return statements with zero values
LICENSE=	modified-bsd

GO_BUILD_PATTERN=	.

pre-patch:
	cp ${FILESDIR}/go.* ${WRKSRC}

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
