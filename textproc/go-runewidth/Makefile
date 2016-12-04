# $NetBSD: Makefile,v 1.5 2016/12/04 16:30:01 bsiegert Exp $

DISTNAME=	go-runewidth-0.0.1
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mattn/}
GITHUB_PROJECT=	go-runewidth
GITHUB_TAG=	v0.0.1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mattn/go-runewidth
COMMENT=	Provides functions to get fixed width of a string
LICENSE=	mit

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG:S/v//}
GO_SRCPATH=	github.com/mattn/go-runewidth

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
