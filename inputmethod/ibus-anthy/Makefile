# $NetBSD: Makefile,v 1.10 2012/03/10 10:56:13 obache Exp $
#

DISTNAME=	ibus-anthy-1.2.6
PKGREVISION=	1
CATEGORIES=	inputmethod japanese
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	Anthy engine for IBus input platform
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	kasumi>=2.1:../../inputmethod/kasumi
DEPENDS+=	ibus>=1.2.0.20100111:../../inputmethod/ibus
DEPENDS+=	${PYPKGPREFIX}-gtk2>=1.15.2:../../x11/py-gtk2

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

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
PY_PATCHPLIST=		yes
.include "../../lang/python/extension.mk"
.include "../../inputmethod/anthy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
