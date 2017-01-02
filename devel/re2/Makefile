# $NetBSD: Makefile,v 1.3 2017/01/02 08:05:50 mef Exp $

DISTNAME=	re2-20170101
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	2017-01-01

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/re2
COMMENT=	Regular expression library
LICENSE=	modified-bsd

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake pkg-config

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixup pathnames
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	Makefile
SUBST_SED.path=		-e 's|/usr/local|${PREFIX}|g'

.include "../../mk/bsd.pkg.mk"
