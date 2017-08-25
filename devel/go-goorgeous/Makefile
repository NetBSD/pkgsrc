# $NetBSD: Makefile,v 1.3 2017/08/25 17:03:26 jperkin Exp $

DISTNAME=	goorgeous-0.0.20170816
PKGNAME=	go-${DISTNAME}
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
