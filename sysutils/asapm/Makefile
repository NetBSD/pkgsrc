# $NetBSD: Makefile,v 1.5 1999/07/12 00:04:57 jlam Exp $
# FreeBSD Id: Makefile,v 1.5 1998/11/29 12:43:12 asami Exp
#

DISTNAME=		asapm-2.6
CATEGORIES=		sysutils x11
MASTER_SITES=		http://www.tigr.net/afterstep/as-apps/download/asapm/ \
			ftp://ftp.afterstep.org/apps/asapm/ \
			ftp://fuf.sh.cvut.cz/pub/AfterStep/apps/asapm/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.tigr.net/afterstep/as-apps/applet-list.html

DEPENDS=		xpm-3.4k:../../graphics/xpm

ONLY_FOR_PLATFORM=	*-*-i386	# needs apm support

GNU_CONFIGURE=		yes
USE_X11BASE=		yes
CONFIGURE_ARGS+=	--disable-jpeg	# there actually is no JPEG support

.include "../../mk/bsd.pkg.mk"
