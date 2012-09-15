# $NetBSD: Makefile,v 1.10 2012/09/15 10:05:12 obache Exp $
#

DISTNAME=	ibus-hangul-1.4.1
PKGREVISION=	1
CATEGORIES=	inputmethod korean
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	Hangul engine for IBus input platform
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake msgfmt intltool

SUBST_CLASSES+=		epython
SUBST_STAGE.epython=	pre-configure
SUBST_FILES.epython=	setup/ibus-setup-hangul.in
SUBST_SED.epython=	-e 's;exec python;exec ${PYTHONBIN};g'

.include "../../inputmethod/ibus/bad-env-usage.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.libhangul+=	libhangul>=0.1.0
.include "../../inputmethod/libhangul/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
