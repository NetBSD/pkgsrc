# $NetBSD: Makefile,v 1.2 2016/08/20 09:21:45 bsiegert Exp $

GITHUB_TAG=	v1.19.1
DISTNAME=	go-ini-${GITHUB_TAG:S/v//}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=go-ini/}
GITHUB_PROJECT=	ini

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://go-ini.github.io/ini
COMMENT=	INI file read and write functionality in Go
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG:S/v//}
GO_SRCPATH=	gopkg.in/ini.v1

.include "../../devel/go-check/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
