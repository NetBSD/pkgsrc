# $NetBSD: Makefile,v 1.15.2.1 2019/11/17 08:30:07 spz Exp $

DISTNAME=	goorgeous-0.0.20170816
PKGNAME=	go-${DISTNAME}
PKGREVISION=	13
MASTER_SITES=	${MASTER_SITE_GITHUB:=chaseadamsio/}
CATEGORIES=	devel
GITHUB_TAG=	16f200711ca25290fa82178ce651f31f0fea17d8
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chaseadamsio/goorgeous
COMMENT=	Go org syntax parser to HTML
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/chaseadamsio/goorgeous

.include "../../devel/go-blackfriday/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
