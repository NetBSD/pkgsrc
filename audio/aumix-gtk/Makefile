# $NetBSD: Makefile,v 1.24 2013/09/02 19:50:52 adam Exp $

.include "../../audio/aumix/Makefile.common"

PKGNAME=	${DISTNAME:S/aumix/aumix-gtk/}
PKGREVISION=	8

COMMENT+=	(ncurses and GTK+ 2.0 interfaces)

CONFLICTS=	aumix-[0-9]*

USE_TOOLS+=	pkg-config

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/^--without-gtk$//}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
