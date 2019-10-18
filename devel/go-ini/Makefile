# $NetBSD: Makefile,v 1.20 2019/10/18 14:58:45 bsiegert Exp $

GITHUB_TAG=	v1.19.1
DISTNAME=	go-ini-${GITHUB_TAG:S/v//}
PKGREVISION=	18
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=go-ini/}
GITHUB_PROJECT=	ini

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/go-ini/ini
COMMENT=	INI file read and write functionality in Go
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG:S/v//}
GO_SRCPATH=	gopkg.in/ini.v1

.include "../../devel/go-check/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
