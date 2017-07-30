# $NetBSD: Makefile,v 1.4 2017/07/30 22:32:22 wiz Exp $

DISTNAME=	jiffy-0.14.8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=davisp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/davisp/jiffy/
COMMENT=	JSON NIFs for Erlang
LICENSE=	mit AND modified-bsd

GITHUB_PROJECT=	jiffy

USE_LANGUAGES=	c c++

SUBST_CLASSES+=		vsn
SUBST_STAGE.vsn=	pre-build
SUBST_MESSAGE.vsn=	Fixing package version
SUBST_FILES.vsn=	src/jiffy.app.src
SUBST_SED.vsn=		-e 's|vsn, git|vsn, "${PKGVERSION_NOREV}"|'

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
