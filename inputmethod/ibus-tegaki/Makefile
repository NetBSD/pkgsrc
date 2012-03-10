# $NetBSD: Makefile,v 1.3 2012/03/10 10:56:14 obache Exp $
#

DISTNAME=	ibus-tegaki-0.3.1
PKGREVISION=	1
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

SUBST_CLASSES+=		epython
SUBST_STAGE.epython=	pre-configure
SUBST_FILES.epython=	ibus-engine-tegaki.in
SUBST_SED.epython=	-e 's;exec python;exec ${PYTHONBIN};g'

EGG_NAME=		${DISTNAME:S/-/_/}

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
