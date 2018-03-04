# $NetBSD: Makefile,v 1.14 2018/03/04 15:52:20 bsiegert Exp $

DISTNAME=		go-text-20151217
PKGREVISION=		8
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		text
GITHUB_TAG=		cf4986612c

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		http://golang.org/
COMMENT=		Supplementary text processing libraries for Go
LICENSE=		modified-bsd

GO_SRCPATH=		golang.org/x/text
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

CHECK_RELRO_SKIP+=	bin/colcmp

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
