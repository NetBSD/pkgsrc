# $NetBSD: Makefile,v 1.7 2012/09/15 10:05:11 obache Exp $
#

DISTNAME=	ibus-array-0.0.2
PKGREVISION=	6
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://ibus-array.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus-array/
COMMENT=	Array 30 Input Method for iBus
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

SUBST_CLASSES+=		epython
SUBST_STAGE.epython=	pre-configure
SUBST_FILES.epython=	setup/ibus-setup-array.in
SUBST_SED.epython=	-e 's;exec python;exec ${PYTHONBIN};g'

.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
