# $NetBSD: Makefile,v 1.13 2004/01/23 21:50:44 jmmv Exp $

DISTNAME=	kdebindings-2.2.1
PKGREVISION=	5
CATEGORIES=	devel
COMMENT=	Additional language bindings for KDE integrated X11 desktop

.include "../../x11/kde2/Makefile.kde2"

USE_BUILDLINK2=		YES

CONFIGURE_ARGS+=	--without-java
CONFIGURE_ENV+=		ac_cv_have_mozilla=no
CONFIGURE_ENV+=		PYTHONINC="-Ino"
CONFIGURE_ENV+=		PYTHONLIB="-Lno"

.include "../../x11/gtk/buildlink2.mk"
.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdebase2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
