# $NetBSD: Makefile,v 1.7 2020/04/21 12:31:19 jperkin Exp $

DISTNAME=	re2-20200101
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	2020-01-01

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/re2
COMMENT=	Regular expression library
LICENSE=	modified-bsd

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake gsed pkg-config

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixup pathnames
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	Makefile
SUBST_SED.path=		-e 's|/usr/local|${PREFIX}|g'

.include "../../mk/bsd.pkg.mk"
