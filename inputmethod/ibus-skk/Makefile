# $NetBSD: Makefile,v 1.1.1.1 2010/08/07 02:07:12 obache Exp $
#

DISTNAME=	ibus-skk-0.0.10
CATEGORIES=	inputmethod japanese
MASTER_SITES=	http://cloud.github.com/downloads/ueno/ibus-skk/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/ueno/ibus-skk/
COMMENT=	Japanese SKK input engine for IBus
LICENSE=	gnu-gpl-v2

DEPENDS+=	ibus-[0-9]*:../../inputmethod/ibus

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool msgfmt

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-configure
SUBST_FILES.prefix=	setup/config.py
SUBST_SED.prefix=	-e 's|/usr/local|${PREFIX}|g'

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
