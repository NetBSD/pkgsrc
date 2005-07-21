# $NetBSD: Makefile,v 1.2 2005/07/21 16:29:43 wiz Exp $

.include "../../audio/aumix/Makefile.common"

PKGNAME=	${DISTNAME:S/aumix/aumix-gtk/}

COMMENT+=	(ncurses and GTK+ 2.0 interfaces)

CONFLICTS=	aumix-[0-9]*

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/^--without-gtk$//}

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
