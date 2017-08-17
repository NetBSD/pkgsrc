# $NetBSD: Makefile,v 1.1 2017/08/17 01:29:44 gavan Exp $

DISTNAME=	go-i18n-1.8.1
MASTER_SITES=	${MASTER_SITE_GITHUB:=nicksnyder/}
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nicksnyder/go-i18n/
COMMENT=	Translate your Go program into multiple languages with templates and CLDR plural support.
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/nicksnyder/go-i18n

.include "../../www/go-toml-pelletier/buildlink3.mk"
.include "../../devel/go-yaml/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"

