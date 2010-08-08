# $NetBSD: Makefile,v 1.1.1.1 2010/08/08 00:42:23 obache Exp $
#

DISTNAME=	ibus-tegaki-0.3.1
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Tegaki integration in ibus
LICENSE=	gnu-gpl-v2

DEPENDS+=	tegaki-pygtk>=0.3:../../inputmethod/tegaki-pygtk
DEPENDS+=	ibus>=1.2:../../inputmethod/ibus

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

SUBST_CLASSES+=		epython
SUBST_STAGE.epython=	pre-configure
SUBST_FILES.epython=	ibus-engine-tegaki.in
SUBST_SED.epython=	-e 's;exec python;exec ${PYTHONBIN};g'

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
