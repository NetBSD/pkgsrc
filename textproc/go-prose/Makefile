# $NetBSD: Makefile,v 1.28 2020/11/08 21:59:35 bsiegert Exp $

DISTNAME=	prose-0.0.20170806
PKGNAME=	go-${DISTNAME}
PKGREVISION=	24
MASTER_SITES=	${MASTER_SITE_GITHUB:=jdkato/}
CATEGORIES=	textproc
GITHUB_TAG=	a678fc7b3ceb0f38ff832c337dea083902c349b2
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jdkato/prose
COMMENT=	Text processing including tokenization, tagging, and extraction
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/jdkato/prose

.include "../../math/go-stats/buildlink3.mk"
.include "../../devel/go-shuffle/buildlink3.mk"
.include "../../devel/go-cli/buildlink3.mk"
.include "../../textproc/go-sentences/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
