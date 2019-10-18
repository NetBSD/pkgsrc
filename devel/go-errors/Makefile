# $NetBSD: Makefile,v 1.16 2019/10/18 14:58:47 bsiegert Exp $

DISTNAME=	errors-0.8.0
PKGNAME=	go-${DISTNAME}
PKGREVISION=	9
MASTER_SITES=	${MASTER_SITE_GITHUB:=pkg/}
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pkg/errors
COMMENT=	Simple error handling primitives
LICENSE=	2-clause-bsd

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/pkg/errors

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
