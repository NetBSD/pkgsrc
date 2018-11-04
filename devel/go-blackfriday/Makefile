# $NetBSD: Makefile,v 1.7 2018/11/04 18:37:58 bsiegert Exp $

DISTNAME=	blackfriday-1.5.1
PKGNAME=	go-${DISTNAME}
PKGREVISION=	1
MASTER_SITES=	${MASTER_SITE_GITHUB:=russross/}
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/russross/blackfriday
COMMENT=	Blackfriday: a markdown processor for Go
LICENSE=	2-clause-bsd

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/russross/blackfriday

.include "../../devel/go-sanitized_anchor_name/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
