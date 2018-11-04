# $NetBSD: Makefile,v 1.7 2018/11/04 18:37:58 bsiegert Exp $

DISTNAME=	amber-0.0.20160421
PKGNAME=	go-${DISTNAME}
PKGREVISION=	4
MASTER_SITES=	${MASTER_SITE_GITHUB:=eknkc/}
CATEGORIES=	devel
GITHUB_TAG=	91774f050c1453128146169b626489e60108ec03
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/eknkc/amber
COMMENT=	Templating engine for Go inspired by HAML and Jade
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/eknkc/amber

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
