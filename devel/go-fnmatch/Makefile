# $NetBSD: Makefile,v 1.16 2020/04/12 11:01:31 bsiegert Exp $

DISTNAME=	fnmatch-0.0.20160404
PKGNAME=	go-${DISTNAME}
PKGREVISION=	15
MASTER_SITES=	${MASTER_SITE_GITHUB:=danwakefield/}
CATEGORIES=	devel
GITHUB_TAG=	cbb64ac3d964b81592e64f957ad53df015803288
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/danwakefield/fnmatch
COMMENT=	Update clone of kballards golang fnmatch gist
LICENSE=	2-clause-bsd

GO_DIST_BASE=	${PKGBASE:S/go-//}-${GITHUB_TAG}
GO_SRCPATH=	${HOMEPAGE:S,https://,,}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
