# $NetBSD: Makefile,v 1.7 2014/05/09 07:37:09 wiz Exp $

DISTNAME=	ibus-tegaki-0.3.1
PKGREVISION=	2
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Tegaki integration in ibus
LICENSE=	gnu-gpl-v2

DEPENDS+=	tegaki-pygtk>=0.3:../../inputmethod/tegaki-pygtk
DEPENDS+=	ibus>=1.2:../../inputmethod/ibus
DEPENDS+=	${PYPKGPREFIX}-ibus-python-[0-9]*:../../inputmethod/ibus-python

USE_LANGUAGES=	# none

SUBST_CLASSES+=		epython
SUBST_STAGE.epython=	pre-configure
SUBST_FILES.epython=	ibus-engine-tegaki.in
SUBST_SED.epython=	-e 's;exec python;exec ${PYTHONBIN};g'

EGG_NAME=		${DISTNAME:S/-/_/}
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-gtk2 via py-ibus-python

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
