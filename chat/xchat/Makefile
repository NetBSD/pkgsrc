# $NetBSD: Makefile,v 1.47 2007/04/17 22:16:00 adrianp Exp $

.include "Makefile.common"

MAINTAINER=		tron@NetBSD.org

COMMENT=	X11 (X Window System) IRC client, using the GTK2 toolkit

CONFLICTS=		xchat-gnome-[0-9]*

USE_TOOLS+=		msgfmt
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--enable-tcl=no
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--enable-xft

LDFLAGS.IRIX+=		-lX11

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.10.0
.include "../../x11/gtk2/buildlink3.mk"

.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=	YES
CONFIGURE_ARGS+=	--disable-mmx

.if empty(PKG_BUILD_OPTIONS.gtk2+:Mquartz)
LDFLAGS.Darwin+=	-lX11
.else
CONFIGURE_ARGS+=	--disable-xlib
.endif
.endif

INSTALLATION_DIRS+=	share/doc/xchat lib/xchat/plugins

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xchat/
	${INSTALL_DATA} ${WRKSRC}/faq.html ${PREFIX}/share/doc/xchat/
	${INSTALL_DATA} ${WRKSRC}/plugins/plugin20.html \
		${PREFIX}/share/doc/xchat/

.include "../../mk/bsd.pkg.mk"
