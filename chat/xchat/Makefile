# $NetBSD: Makefile,v 1.106 2018/08/22 09:43:03 wiz Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME}
PKGREVISION=	34
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	X11 (X Window System) IRC client, using the GTK2 toolkit

CONFLICTS=		xchat-gnome-[0-9]*

USE_TOOLS+=		msgfmt
USE_PKGLOCALEDIR=	YES
GCONF_SCHEMAS=		apps_xchat_url_handler.schemas

CONFIGURE_ARGS+=	--enable-tcl=no
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-python

LDFLAGS.IRIX+=		-lX11

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.20.0
.include "../../x11/gtk2/buildlink3.mk"

.if ${OPSYS} == "Darwin"
.  if empty(PKG_BUILD_OPTIONS.gtk2:Mquartz)
CONFIGURE_ARGS+=	--enable-xft
LDFLAGS.Darwin+=	-L${PREFIX}/lib -lX11
.  else
CONFIGURE_ARGS+=	--disable-xlib
.  endif
.else
CONFIGURE_ARGS+=	--enable-xft
.endif

INSTALLATION_DIRS+=	share/doc/xchat lib/xchat/plugins include/xchat

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/xchat/
	${INSTALL_DATA} ${WRKSRC}/faq.html ${DESTDIR}${PREFIX}/share/doc/xchat/
	${INSTALL_DATA} ${WRKSRC}/plugins/plugin20.html \
		${DESTDIR}${PREFIX}/share/doc/xchat/
	${INSTALL_DATA} ${WRKSRC}/plugins/xchat-plugin.h \
		${DESTDIR}${PREFIX}/include/xchat/

.if !empty(PKG_OPTIONS:Mgnome)

	${INSTALL_DATA_DIR} ${DESTDIR}${GCONF_SCHEMAS_DIR}
# In case there're ever additional schema files, use ODE loop.
	${GCONF_SCHEMAS:@.s.@${INSTALL_DATA} ${WRKSRC}/src/common/dbus/${.s.} \
		${DESTDIR}${GCONF_SCHEMAS_DIR}/@}
.endif

.include "../../mk/bsd.pkg.mk"
