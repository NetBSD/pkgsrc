# $NetBSD: Makefile,v 1.18 2005/12/11 09:40:46 wiz Exp $
#

DISTNAME=		xine-ui-0.99.2
PKGREVISION=		3
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xine/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://xinehq.de/
COMMENT=		Skinned xlib-based xine GUI

BUILD_USES_MSGFMT=	YES

BUILDLINK_DEPENDS.curl+=	curl>7.10.2

USE_PKGLOCALEDIR=	YES
USE_DIRS+=		xdg-1.1
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_GNU_READLINE=	yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
