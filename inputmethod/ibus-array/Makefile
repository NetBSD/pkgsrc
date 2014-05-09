# $NetBSD: Makefile,v 1.11 2014/05/09 07:37:08 wiz Exp $

DISTNAME=	ibus-array-0.0.2
PKGREVISION=	7
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://ibus-array.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus-array/
COMMENT=	Array 30 Input Method for iBus
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-ibus-python-[0-9]*:../../inputmethod/ibus-python

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

SUBST_CLASSES+=		epython
SUBST_STAGE.epython=	pre-configure
SUBST_FILES.epython=	setup/ibus-setup-array.in
SUBST_SED.epython=	-e 's;exec python;exec ${PYTHONBIN};g'

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-gtk2 via py-ibus-python

.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
