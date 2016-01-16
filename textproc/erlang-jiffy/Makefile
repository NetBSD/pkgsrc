# $NetBSD: Makefile,v 1.2 2016/01/16 17:39:57 fhajny Exp $

DISTNAME=	jiffy-0.14.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=davisp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/davisp/jiffy/
COMMENT=	JSON NIFs for Erlang
LICENSE=	mit

GITHUB_PROJECT=	jiffy
GITHUB_TAG=	${PKGVERSION_NOREV}

USE_LANGUAGES=	c c++

SUBST_CLASSES+=		vsn
SUBST_STAGE.vsn=	pre-build
SUBST_MESSAGE.vsn=	Fixing package version
SUBST_FILES.vsn=	src/jiffy.app.src
SUBST_SED.vsn=		-e 's,git,"${PKGVERSION_NOREV}",'

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
