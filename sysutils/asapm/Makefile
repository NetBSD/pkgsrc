# $NetBSD: Makefile,v 1.35 2006/11/18 08:27:10 rillig Exp $
#

DISTNAME=		asapm-2.11
PKGREVISION=    	4
CATEGORIES=		sysutils x11
MASTER_SITES=		http://www.tigr.net/afterstep/download/asapm/ \
			ftp://ftp.afterstep.org/apps/asapm/ \
			ftp://fuf.sh.cvut.cz/pub/AfterStep/apps/asapm/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.tigr.net/afterstep/detail.pl?applet=asapm
COMMENT=		Laptop battery status display for X11

.if !exists(/usr/include/machine/apmvar.h)
PKG_FAIL_REASON+=	"APM needs /usr/include/machine/apmvar.h to build."
.endif

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-jpeg	# there actually is no JPEG support
CONFIGURE_ARGS+=	--with-xpm
CONFIGURE_ARGS+=	--with-xpm-includes=${BUILDLINK_PREFIX.xpm}/include
CONFIGURE_ARGS+=	--with-xpm-library=${BUILDLINK_PREFIX.xpm}/lib

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
