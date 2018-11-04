# $NetBSD: Makefile,v 1.7 2018/11/04 18:38:00 bsiegert Exp $

DISTNAME=	osext-0.0.20151222
PKGNAME=	go-${DISTNAME}
PKGREVISION=	4
MASTER_SITES=	${MASTER_SITE_GITHUB:=kardianos/}
CATEGORIES=	devel
GITHUB_TAG=	29ae4ffbc9a6fe9fb2bc5029050ce6996ea1d3bc
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kardianos/osext
COMMENT=	Extensions to the standard "os" package
LICENSE=	modified-bsd

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/kardianos/osext

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
