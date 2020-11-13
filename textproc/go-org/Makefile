# $NetBSD: Makefile,v 1.8 2020/11/13 19:26:23 bsiegert Exp $

DISTNAME=		go-org-1.1.0
PKGREVISION=		6
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GITHUB:=niklasfasching/}
GITHUB_PROJECT=		go-org
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/niklasfasching/go-org
COMMENT=		Go Org mode parser with html & pretty printed org rendering
LICENSE=		mit

USE_TOOLS+=	bash
REPLACE_BASH+=	etc/generate-fixtures
REPLACE_BASH+=	etc/generate-gh-pages
REPLACE_BASH+=	etc/githooks/pre-push

GO_SRCPATH=		github.com/niklasfasching/go-org
GO_DIST_BASE=		${DISTNAME}


.include "../../net/go-net/buildlink3.mk"
.include "../../textproc/go-chroma/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
