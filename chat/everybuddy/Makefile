# $NetBSD: Makefile,v 1.5 2003/05/02 11:54:00 wiz Exp $

.include "Makefile.common"
PKGREVISION=	3

USE_BUILDLINK2=	yes
CONFLICTS+=	everybuddy-gnome-[0-9]*

.include "../../audio/esound/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
