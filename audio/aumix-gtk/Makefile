# $NetBSD: Makefile,v 1.39 2020/08/17 20:18:04 leot Exp $

.include "../../audio/aumix/Makefile.common"

PKGNAME=	${DISTNAME:S/aumix/aumix-gtk/}
PKGREVISION=	22

COMMENT+=	(curses and GTK+ 2.0 interfaces)

CONFLICTS=	aumix-[0-9]*

USE_TOOLS+=	pkg-config

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/^--without-gtk$//}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
