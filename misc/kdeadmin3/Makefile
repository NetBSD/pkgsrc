# $NetBSD: Makefile,v 1.8 2003/03/11 13:22:20 markd Exp $

DISTNAME=	kdeadmin-3.1
CATEGORIES=	misc
COMMENT=	System administration tools for the KDE integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-shadow
.else
CONFIGURE_ARGS+=	--without-shadow
.endif

.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
