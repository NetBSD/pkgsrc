# $NetBSD: Makefile,v 1.22 2020/11/13 19:26:11 bsiegert Exp $

DISTNAME=	mapstructure-bep-0.0.20180511
PKGNAME=	go-${DISTNAME}
PKGREVISION=	21
MASTER_SITES=	${MASTER_SITE_GITHUB:=bep/}
CATEGORIES=	devel
GITHUB_TAG=	bb74f1db0675b241733089d5a1faa5dd8b0ef57b
GITHUB_PROJECT=	${PKGBASE:S/^go-//:S/-bep//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bep/mapstructure
COMMENT=	Library for decoding generic map values into native structures
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/bep/mapstructure

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
