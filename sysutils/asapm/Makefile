# $NetBSD: Makefile,v 1.3 1999/04/12 17:39:46 jlam Exp $
# FreeBSD Id: Makefile,v 1.5 1998/11/29 12:43:12 asami Exp
#

DISTNAME=	asapm-2.6
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.tigr.net/afterstep/as-apps/download/asapm/ \
		ftp://ftp.afterstep.org/apps/asapm/ \
		ftp://fuf.sh.cvut.cz/pub/AfterStep/apps/asapm/

MAINTAINER=	lamj@stat.cmu.edu
HOMEPAGE=	http://www.tigr.net/afterstep/as-apps/applet-list.html

DEPENDS+=	xpm-3.4k:../../graphics/xpm

ONLY_FOR_ARCHS=	i386		# needs apm support

GNU_CONFIGURE=	yes
USE_X11BASE=	yes

.include "../../mk/bsd.pkg.mk"
