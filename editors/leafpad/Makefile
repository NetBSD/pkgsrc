# $NetBSD: Makefile,v 1.3 2004/12/05 11:42:55 jmmv Exp $
#

DISTNAME=	leafpad-0.7.8
CATEGORIES=	editors gnome
MASTER_SITES=	http://tarot.freeshell.org/leafpad/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://tarot.freeshell.org/leafpad/
COMMENT=	Simple and light text editor using GTK+

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	YES

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
