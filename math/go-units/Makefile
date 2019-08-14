# $NetBSD: Makefile,v 1.9 2019/08/14 15:45:44 bsiegert Exp $

DISTNAME=	units-0.0.20151021
PKGNAME=	go-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=alecthomas/}
GITHUB_PROJECT=	${PKGBASE:S/^go-//}
GITHUB_TAG=	2efee857e7cfd4f3d0138cc3cbb1b4966962b93a

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/alecthomas/units
COMMENT=	Helpful unit multipliers and functions for Go
LICENSE=	mit

GO_DIST_BASE=	${PKGBASE:S/go-//}-${GITHUB_TAG}
GO_SRCPATH=	${HOMEPAGE:S,https://,,}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
