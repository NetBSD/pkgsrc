# $NetBSD: Makefile,v 1.3 2002/10/05 17:29:19 wiz Exp $

.include "Makefile.common"
PKGREVISION=	1

USE_BUILDLINK2=	yes
CONFLICTS+=	everybuddy-gnome-[0-9]*

.include "../../audio/esound/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
