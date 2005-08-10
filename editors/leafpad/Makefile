# $NetBSD: Makefile,v 1.6 2005/08/10 20:56:16 jlam Exp $
#

DISTNAME=	leafpad-0.7.8
CATEGORIES=	editors gnome
MASTER_SITES=	http://tarot.freeshell.org/leafpad/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://tarot.freeshell.org/leafpad/
COMMENT=	Simple and light text editor using GTK+

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	YES

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
