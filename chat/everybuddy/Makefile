# $NetBSD: Makefile,v 1.6 2003/07/13 13:50:45 wiz Exp $

.include "Makefile.common"
PKGREVISION=	4

USE_BUILDLINK2=	yes
CONFLICTS+=	everybuddy-gnome-[0-9]*

.include "../../audio/esound/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
