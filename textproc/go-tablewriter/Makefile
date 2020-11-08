# $NetBSD: Makefile,v 1.22 2020/11/08 21:59:36 bsiegert Exp $

DISTNAME=	tablewriter-0.0.20180506
PKGNAME=	go-${DISTNAME}
PKGREVISION=	21
MASTER_SITES=	${MASTER_SITE_GITHUB:=olekukonko/}
CATEGORIES=	textproc
GITHUB_PROJECT=	${PKGBASE:S/^go-//}
GITHUB_TAG=	d4647c9c7a84d847478d890b816b7d8b62b0b279

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/olekukonko/tablewriter
COMMENT=	ASCII table in Go
LICENSE=	mit

GO_DIST_BASE=	${PKGBASE:S/go-//}-${GITHUB_TAG}
GO_SRCPATH=	${HOMEPAGE:S,https://,,}

.include "../../textproc/go-runewidth/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
