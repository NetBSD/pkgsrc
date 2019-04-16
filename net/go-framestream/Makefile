# $NetBSD: Makefile,v 1.5 2019/04/16 18:41:09 bsiegert Exp $

DISTNAME=		go-framestream-0.1.0
PKGREVISION=		4
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=farsightsec/}
GITHUB_PROJECT=		golang-framestream
GITHUB_TAG=		tags/v${PKGVERSION_NOREV}
GITHUB_TYPE=		tag

HOMEPAGE=		http://${GO_SRCPATH}
COMMENT=		Go language implementation of framestream protocol
LICENSE=		apache-2.0

GO_SRCPATH=		github.com/farsightsec/golang-framestream
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG:S!/!-!}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
