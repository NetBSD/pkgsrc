# $NetBSD: Makefile,v 1.15.2.1 2019/11/17 08:30:10 spz Exp $

DISTNAME=	mapstructure-0.0.20160212
PKGNAME=	go-${DISTNAME}
PKGREVISION=	13
MASTER_SITES=	${MASTER_SITE_GITHUB:=mitchellh/}
CATEGORIES=	devel
GITHUB_TAG=	d2dd0262208475919e1a362f675cfc0e7c10e905
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mitchellh/mapstructure
COMMENT=	Library for decoding generic map values into native structures
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/mitchellh/mapstructure

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
