# $NetBSD: Makefile,v 1.1.1.1 2002/05/31 13:20:19 skrll Exp $

DISTNAME=	kdeadmin-3.0.1
CATEGORIES=	misc
COMMENT=	System administration tools for the KDE integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK_ONLY=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-shadow
.else
CONFIGURE_ARGS+=	--without-shadow
.endif

.include "../../x11/kde3/buildlink.mk"
.include "../../x11/kdebase3/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
