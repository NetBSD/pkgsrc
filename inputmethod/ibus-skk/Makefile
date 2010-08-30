# $NetBSD: Makefile,v 1.4 2010/08/30 07:36:48 obache Exp $
#

DISTNAME=	ibus-skk-1.0.0
CATEGORIES=	inputmethod japanese
MASTER_SITES=	http://cloud.github.com/downloads/ueno/ibus-skk/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/ueno/ibus-skk/
COMMENT=	Japanese SKK input engine for IBus
LICENSE=	gnu-gpl-v2

DEPENDS+=	ibus-[0-9]*:../../inputmethod/ibus

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-configure
SUBST_FILES.prefix=	setup/config.py
SUBST_SED.prefix=	-e 's|/usr/local|${PREFIX}|g'

SUBST_CLASSES+=		epython
SUBST_STAGE.epython=	pre-configure
SUBST_FILES.epython=	engine/ibus-engine-skk.in setup/ibus-setup-skk.in
SUBST_SED.epython=	-e 's;exec python;exec ${PYTHONBIN};g'

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
