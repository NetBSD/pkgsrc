# $NetBSD: Makefile,v 1.20 2020/02/02 14:19:02 bsiegert Exp $

DISTNAME=	go-i18n-1.10.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=nicksnyder/}
PKGREVISION=	13
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nicksnyder/go-i18n/
COMMENT=	Translate your Go program into multiple languages
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/nicksnyder/go-i18n

.include "../../www/go-toml-pelletier/buildlink3.mk"
.include "../../devel/go-yaml/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
