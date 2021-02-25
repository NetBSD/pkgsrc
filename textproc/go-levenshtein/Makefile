# $NetBSD: Makefile,v 1.1 2021/02/25 01:11:32 gutteridge Exp $

DISTNAME=	levenshtein-1.2.3
PKGNAME=	go-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=agext/}
CATEGORIES=	textproc
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/agext/levenshtein
COMMENT=	Go package providing Levenshtein distance and similarity metrics
LICENSE=	apache-2.0

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/agext/levenshtein

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
