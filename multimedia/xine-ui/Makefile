# $NetBSD: Makefile,v 1.28.2.1 2007/03/05 12:11:41 ghen Exp $
#

DISTNAME=		xine-ui-0.99.4
PKGREVISION=		8
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xine/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xinehq.de/
COMMENT=		Skinned xlib-based xine GUI

BUILDLINK_API_DEPENDS.curl+=	curl>7.10.2

USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		msgfmt
USE_DIRS+=		xdg-1.1
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_GNU_READLINE=	yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
