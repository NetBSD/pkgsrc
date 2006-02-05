# $NetBSD: Makefile,v 1.5 2006/02/05 23:08:05 joerg Exp $

.include "../../audio/aumix/Makefile.common"

PKGNAME=	${DISTNAME:S/aumix/aumix-gtk/}
PKGREVISION=	2

COMMENT+=	(ncurses and GTK+ 2.0 interfaces)

CONFLICTS=	aumix-[0-9]*

USE_TOOLS+=	pkg-config

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/^--without-gtk$//}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
