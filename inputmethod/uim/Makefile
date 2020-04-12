# $NetBSD: Makefile,v 1.162 2020/04/12 08:28:53 adam Exp $

PKGREVISION= 4
.include "../../inputmethod/uim/Makefile.common"

COMMENT=	Multilingual input method library
LICENSE=	modified-bsd

CONFLICTS+=	uim-qt4-immodule-[0-9]*

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

# Do not segfault uim-module-manager during build
BUILDLINK_TRANSFORM+=	opt:-O2:-O1

USE_TOOLS+=	gmake pkg-config
USE_TOOLS+=	intltool msgfmt msgmerge xgettext
USE_TOOLS+=	autopoint
USE_LANGUAGES=	c99 gnu++03

# Avoid finding mono tool and breaking.
MAKE_FLAGS+=	CSI=

LDFLAGS.SunOS+=	-mimpure-text
CFLAGS.SunOS+=	-D__EXTENSIONS__

UIM_MODULES=	anthy-utf8 skk tutcode byeoru latin elatin xmload \
		pyload py pyunihan viqr ipa-x-sampa look ajax-ime \
		google-cgiapi-jp baidu-olime-jp

BUILD_DEFS+=	PKG_SYSCONFBASE

CONFIGURE_ARGS+=	--disable-emacs
CONFIGURE_ARGS+=	--disable-fep
CONFIGURE_ARGS+=	--disable-kde4-applet
CONFIGURE_ARGS+=	--disable-gnome-applet
CONFIGURE_ARGS+=	--disable-gnome3-applet
CONFIGURE_ARGS+=	--with-libgcroots=installed
CONFIGURE_ARGS+=	--with-anthy-utf8
CONFIGURE_ARGS+=	--with-sqlite3
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

PKGCONFIG_OVERRIDE+=	${WRKSRC}/uim.pc.in

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples

EGDIR=			${PREFIX}/share/examples/uim
CONF_FILES=		${EGDIR}/loader.scm \
			${PKG_SYSCONFDIR}/loader.scm
CONF_FILES+=		${EGDIR}/installed-modules.scm \
			${PKG_SYSCONFDIR}/installed-modules.scm

PKG_SYSCONFSUBDIR=	uim
INSTALLATION_DIRS+=	share/doc/uim

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/COMPATIBILITY ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/CUSTOM ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/DOT-UIM ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/HELPER-CANDWIN ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/HELPER-PROTOCOL ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/KEY ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/PLUGIN ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/UIM-SCM ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/UIM-SH ${DESTDIR}${PREFIX}/share/doc/uim

.include "options.mk"

SUBST_CLASSES+=		gtk
SUBST_STAGE.gtk=	post-configure
SUBST_MESSAGE.gtk=	Correcting executable name in .desktop file
SUBST_FILES.gtk+=	uim.desktop
SUBST_SED.gtk+=		-e "s,uim-pref-gtk,${UIM_PREF_PROGRAM},g"

.include "modules.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/editline/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgcroots+=	libgcroots>=0.2.3
.include "../../devel/libgcroots/buildlink3.mk"
.include "../../inputmethod/anthy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
