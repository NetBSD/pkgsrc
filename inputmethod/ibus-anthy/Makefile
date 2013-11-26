# $NetBSD: Makefile,v 1.14 2013/11/26 11:22:15 obache Exp $
#

DISTNAME=	ibus-anthy-1.5.4
PKGREVISION=	1
CATEGORIES=	inputmethod japanese
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	Anthy engine for IBus input platform
LICENSE=	gnu-gpl-v2

DEPENDS+=	kasumi>=2.1:../../inputmethod/kasumi
DEPENDS+=	ibus>=1.5.4:../../inputmethod/ibus
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config msgfmt gmake intltool

FIND_PREFIX:=	KASUMI_DIR=kasumi
.include "../../mk/find-prefix.mk"

CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale
CONFIGURE_ARGS+=	--with-kasumi-exec=${KASUMI_DIR}/bin/kasumi
CONFIGURE_ARGS+=	--with-kasumi-icon=${KASUMI_DIR}/share/pixmaps/kasumi.png
#CONFIGURE_ARGS+=	--enable-pygtk2-anthy

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.26.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
PY_PATCHPLIST=		yes
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../inputmethod/anthy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
