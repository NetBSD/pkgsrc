# $NetBSD: Makefile,v 1.16 2018/06/12 17:50:29 bsiegert Exp $

DISTNAME=		go-text-20151217
PKGREVISION=		10
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
