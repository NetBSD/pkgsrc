# $NetBSD: Makefile,v 1.5 2005/07/21 16:29:49 wiz Exp $
#

DISTNAME=	leafpad-0.7.8
CATEGORIES=	editors gnome
MASTER_SITES=	http://tarot.freeshell.org/leafpad/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://tarot.freeshell.org/leafpad/
COMMENT=	Simple and light text editor using GTK+

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	YES

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
