# $NetBSD: Makefile,v 1.33 2021/07/13 11:36:40 bsiegert Exp $

DISTNAME=	properties-1.7.0
PKGNAME=	go-${DISTNAME}
PKGREVISION=	30
MASTER_SITES=	${MASTER_SITE_GITHUB:=magiconair/}
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/magiconair/properties
COMMENT=	Java properties scanner for Go
LICENSE=	2-clause-bsd

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/magiconair/properties

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
