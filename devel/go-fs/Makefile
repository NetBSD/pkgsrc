# $NetBSD: Makefile,v 1.8.2.1 2019/02/08 12:03:09 spz Exp $

DISTNAME=	fs-0.0.20131111
PKGNAME=	go-${DISTNAME}
PKGREVISION=	6
MASTER_SITES=	${MASTER_SITE_GITHUB:=kr/}
CATEGORIES=	devel
GITHUB_TAG=	2788f0dbd16903de03cb8186e5c7d97b69ad387b
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kr/fs
COMMENT=	Package fs provides filesystem-related functions
LICENSE=	modified-bsd

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/kr/fs

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
