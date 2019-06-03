# $NetBSD: Makefile,v 1.247 2019/06/03 21:24:04 maya Exp $

.include "Makefile.common"

CATEGORIES=	devel gnome
COMMENT=	Some useful routines for C programming (glib2)

DISTINFO_FILE=	${.CURDIR}/../../devel/glib2/distinfo
PATCHDIR=	${.CURDIR}/../../devel/glib2/patches

.include "options.mk"

MESON_ARGS+=	-Dinstalled_tests=false
# Avoid linux dependency on libmount-dev
MESON_ARGS+=	-Dlibmount=false

LDFLAGS.SunOS+=	-lintl -lnsl

REPLACE_PYTHON+=	gio/gio-querymodules-wrapper.py
REPLACE_PYTHON+=	gio/tests/gengiotypefuncs.py
REPLACE_PYTHON+=	gio/tests/static-link.py
REPLACE_PYTHON+=	glib/update-gtranslit.py
REPLACE_PYTHON+=	gobject/tests/mkenums.py
REPLACE_PYTHON+=	tests/gen-casefold-txt.py
REPLACE_PYTHON+=	tests/gen-casemap-txt.py

BUILD_DEFS+=		VARBASE
SUBST_CLASSES+=		dbusdb
SUBST_MESSAGE.dbusdb=	Adjust dbus machine uuid path to dbus package
SUBST_STAGE.dbusdb=	pre-configure
SUBST_FILES.dbusdb=	gio/gdbusconnection.c
SUBST_FILES.dbusdb+=	gio/gdbusprivate.c
SUBST_FILES.dbusdb+=	po/glib20.pot
SUBST_FILES.dbusdb+=	po/*.po
SUBST_SED.dbusdb=	-e 's,/var/lib/dbus,${VARBASE}/db/dbus,g'

SUBST_CLASSES+=		xdg
SUBST_MESSAGE.xdg=	Adjust XDG_DATA_DIRS so schemas and pixbuf loaders are found
SUBST_STAGE.xdg=	pre-configure
SUBST_FILES.xdg=	glib/gcharset.c glib/gutils.c gio/xdgmime/xdgmime.c
SUBST_SED.xdg=		-e 's,/usr/local/share/:/usr/share/,${PREFIX}/share,'
SUBST_SED.xdg+=		-e 's,/etc/xdg,${PKG_SYSCONFDIR}/xdg,'
SUBST_SED.xdg+=		-e 's,/usr/share/locale,${PREFIX}/${PKGLOCALEDIR}/locale,'

# to run gdbus-codegen to generate gdbus-daemon-generated.{h,c}
TOOL_DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
PYTHON_FOR_BUILD_ONLY= yes
.include "../../lang/python/application.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/py-meson/build.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
