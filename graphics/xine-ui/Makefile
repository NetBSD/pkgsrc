# $NetBSD: Makefile,v 1.3 2003/05/05 16:32:29 jmmv Exp $
#

DISTNAME=		xine-ui-0.9.20
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xine/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://xinehq.de/
COMMENT=		skinned xlib-based xine gui

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
.include "../../mk/bsd.pkg.mk"
