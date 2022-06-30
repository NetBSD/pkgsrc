# $NetBSD: Makefile,v 1.20 2022/06/30 11:18:31 nia Exp $

DISTNAME=	ibus-tegaki-0.3.1
PKGREVISION=	6
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
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

PYTHON_VERSIONS_ACCEPTED=	27 # py-gtk2 via py-ibus-python

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
