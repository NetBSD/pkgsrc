# $NetBSD: Makefile,v 1.11 2000/07/11 14:53:45 agc Exp $
# FreeBSD Id: Makefile,v 1.5 1998/11/29 12:43:12 asami Exp
#

DISTNAME=		asapm-2.9
CATEGORIES=		sysutils x11
MASTER_SITES=		http://www.tigr.net/afterstep/as-apps/download/asapm/ \
			ftp://ftp.afterstep.org/apps/asapm/ \
			ftp://fuf.sh.cvut.cz/pub/AfterStep/apps/asapm/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.tigr.net/afterstep/as-apps/download/asapm/

.if !exists(/usr/include/machine/apmvar.h)
IGNORE+=		"APM is not available for ${MACHINE_PLATFORM}"
.endif

DEPENDS+=		xpm-*:../../graphics/xpm

GNU_CONFIGURE=		yes
USE_X11=		yes
CONFIGURE_ARGS+=	--disable-jpeg	# there actually is no JPEG support
CONFIGURE_ARGS+=	--with-xpm \
			--with-xpm-includes="`${MAKE} show-xpm-prefix`/include" \
			--with-xpm-library="`${MAKE} show-xpm-prefix`/lib"

.include "../../mk/bsd.pkg.mk"
