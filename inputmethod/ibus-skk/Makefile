# $NetBSD: Makefile,v 1.28 2014/09/10 09:46:00 obache Exp $
#

DISTNAME=	ibus-skk-1.4.2
CATEGORIES=	inputmethod japanese
MASTER_SITES=	https://github.com/ueno/ibus-skk/releases/download/${DISTNAME}/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/ueno/ibus-skk/
COMMENT=	Japanese SKK input engine for IBus
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-configure
SUBST_FILES.prefix=	src/preferences.c
SUBST_SED.prefix=	-e 's|/usr/share|${PREFIX}/share|g'

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/libskk/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
