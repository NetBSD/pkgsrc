# $NetBSD: Makefile,v 1.4 2003/01/27 12:54:52 jmmv Exp $

.include "Makefile.common"
PKGREVISION=	2

USE_BUILDLINK2=	yes
CONFLICTS+=	everybuddy-gnome-[0-9]*

.include "../../audio/esound/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
