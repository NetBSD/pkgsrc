# $NetBSD: Makefile,v 1.11 2003/12/08 14:41:40 wiz Exp $
#

DISTNAME=		xine-ui-0.9.22
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xine/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://xinehq.de/
COMMENT=		Skinned xlib-based xine GUI

BUILD_USES_MSGFMT=	YES
BUILDLINK_DEPENDS.curl=	curl>7.10.2

USE_PKGLOCALEDIR=	YES
USE_BUILDLINK2=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xine-lib/buildlink2.mk"
.include "../../www/curl/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
