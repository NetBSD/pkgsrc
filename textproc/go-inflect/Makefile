# $NetBSD: Makefile,v 1.29 2020/11/13 19:26:22 bsiegert Exp $

DISTNAME=	inflect-0.0.20170411
PKGNAME=	go-${DISTNAME}
PKGREVISION=	25
MASTER_SITES=	${MASTER_SITE_GITHUB:=markbates/}
CATEGORIES=	textproc
GITHUB_TAG=	6cacb66d100482ef7cc366289ccb156020e57e76
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/markbates/inflect
COMMENT=	Inflect library for go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/markbates/inflect

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
