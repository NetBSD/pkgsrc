# $NetBSD: Makefile,v 1.7 2001/11/13 21:15:31 jlam Exp $

DISTNAME=	kdebindings-2.2.1
CATEGORIES=	devel
COMMENT=	Additional language bindings for KDE integrated X11 desktop

.include "../../x11/kde2/Makefile.kde2"

USE_BUILDLINK_ONLY=	YES

CONFIGURE_ARGS+=	--without-java
CONFIGURE_ENV+=		ac_cv_have_mozilla=no
CONFIGURE_ENV+=		PYTHONINC="-Ino"
CONFIGURE_ENV+=		PYTHONLIB="-Lno"

.include "../../x11/gtk/buildlink.mk"
.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdebase2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
