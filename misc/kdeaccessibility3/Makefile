# $NetBSD: Makefile,v 1.35 2008/02/20 10:16:32 markd Exp $

DISTNAME=	kdeaccessibility-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Accessibility support for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_TOOLS+=		pkg-config

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdeaccessibility
PKG_SUPPORTED_OPTIONS=	gstreamer
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgstreamer)
CONFIGURE_ARGS+=	--enable-kttsd-gstreamer
CONFIGURE_ARGS+=	--with-gstreamer
.include "../../multimedia/gstreamer0.8/buildlink3.mk"
.include "../../multimedia/gst-plugins0.8/buildlink3.mk"
PLIST_SUBST+=		HAVE_GST=""
.else
PLIST_SUBST+=		HAVE_GST="@comment "
.endif

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
