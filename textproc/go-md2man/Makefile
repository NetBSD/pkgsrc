# $NetBSD: Makefile,v 1.4 2017/08/25 17:17:05 jperkin Exp $

DISTNAME=	go-md2man-1.0.6
MASTER_SITES=	${MASTER_SITE_GITHUB:=cpuguy83/}
CATEGORIES=	textproc
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cpuguy83/go-md2man/
COMMENT=	Uses blackfriday to process markdown into man pages
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/cpuguy83/go-md2man

.include "../../devel/go-blackfriday/buildlink3.mk"
.include "../../devel/go-sanitized_anchor_name/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
