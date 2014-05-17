# $NetBSD: Makefile,v 1.4 2014/05/17 16:10:45 wiz Exp $
#

DISTNAME=	scim-tegaki-0.1
PKGREVISION=	2
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/0.1/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Tegaki integration in SCIM
LICENSE=	gnu-gpl-v2

DEPENDS+=	tegaki-pygtk>=0.2:../../inputmethod/tegaki-pygtk
DEPENDS+=	scim-python>=0.1.13rc1:../../inputmethod/scim-python

USE_LANGUAGES=	# none

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	src/__init__.py
SUBST_SED.prefix=	-e 's|/usr/local/share|${PREFIX}/share|g'

EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
