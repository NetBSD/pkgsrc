# $NetBSD: Makefile,v 1.7 2018/11/04 18:38:01 bsiegert Exp $

DISTNAME=	purell-0.1.0
PKGNAME=	go-${DISTNAME}
PKGREVISION=	4
MASTER_SITES=	${MASTER_SITE_GITHUB:=PuerkitoBio/}
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PuerkitoBio/purell
COMMENT=	Purell is a tiny Go library to normalize URLs
LICENSE=	modified-bsd

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/PuerkitoBio/purell

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
