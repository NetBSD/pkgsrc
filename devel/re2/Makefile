# $NetBSD: Makefile,v 1.1 2016/02/08 05:46:23 agc Exp $

DISTNAME=	re2
PKGNAME=	re2-20160201
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	2016-02-01

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
