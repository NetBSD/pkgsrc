# $NetBSD: Makefile,v 1.26 2004/04/25 03:21:16 snj Exp $
#

DISTNAME=		asapm-2.11
CATEGORIES=		sysutils x11
MASTER_SITES=		http://www.tigr.net/afterstep/download/asapm/ \
			ftp://ftp.afterstep.org/apps/asapm/ \
			ftp://fuf.sh.cvut.cz/pub/AfterStep/apps/asapm/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.tigr.net/afterstep/detail.pl?applet=asapm
COMMENT=		Laptop battery status display for X11

.if !exists(/usr/include/machine/apmvar.h)
PKG_SKIP_REASON=	"APM is not available for ${MACHINE_PLATFORM}"
.endif

USE_BUILDLINK3=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-jpeg	# there actually is no JPEG support
CONFIGURE_ARGS+=	--with-xpm
CONFIGURE_ARGS+=	--with-xpm-includes=${BUILDLINK_PREFIX.xpm}/include
CONFIGURE_ARGS+=	--with-xpm-library=${BUILDLINK_PREFIX.xpm}/lib

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
