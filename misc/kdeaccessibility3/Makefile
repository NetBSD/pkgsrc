# $NetBSD: Makefile,v 1.9 2005/07/21 16:29:53 wiz Exp $

DISTNAME=	kdeaccessibility-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Accessibility support for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"


.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdeaccessibility
PKG_SUPPORTED_OPTIONS=	gstreamer
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgstreamer)
CONFIGURE_ARGS+=	--enable-kttsd-gstreamer
.include "../../multimedia/gstreamer/buildlink3.mk"
.include "../../multimedia/gst-plugins/buildlink3.mk"
PLIST_SUBST+=		HAVE_GST=""
.else
PLIST_SUBST+=		HAVE_GST="@comment "
.endif

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
