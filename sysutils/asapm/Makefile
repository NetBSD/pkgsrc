# $NetBSD: Makefile,v 1.15 2001/02/17 17:42:10 wiz Exp $
# FreeBSD Id: Makefile,v 1.5 1998/11/29 12:43:12 asami Exp
#

DISTNAME=		asapm-2.9
CATEGORIES=		sysutils x11
MASTER_SITES=		http://www.tigr.net/afterstep/as-apps/download/asapm/ \
			ftp://ftp.afterstep.org/apps/asapm/ \
			ftp://fuf.sh.cvut.cz/pub/AfterStep/apps/asapm/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.tigr.net/afterstep/as-apps/download/asapm/
COMMENT=		Laptop battery status display for X11

.if !exists(/usr/include/machine/apmvar.h)
IGNORE+=		"APM is not available for ${MACHINE_PLATFORM}"
.endif

GNU_CONFIGURE=		YES
USE_X11=		YES
USE_XPM=		YES
CONFIGURE_ARGS+=	--disable-jpeg	# there actually is no JPEG support
EVAL_PREFIX+=		XPMDIR=xpm
CONFIGURE_ARGS+=	--with-xpm \
			--with-xpm-includes="${XPMDIR}/include" \
			--with-xpm-library="${XPMDIR}/lib"

.include "../../mk/bsd.pkg.mk"
