# $NetBSD: Makefile,v 1.18 2001/10/23 13:15:02 jlam Exp $
# FreeBSD Id: Makefile,v 1.5 1998/11/29 12:43:12 asami Exp
#

DISTNAME=		asapm-2.10
CATEGORIES=		sysutils x11
MASTER_SITES=		http://www.tigr.net/afterstep/as-apps/download/asapm/ \
			ftp://ftp.afterstep.org/apps/asapm/ \
			ftp://fuf.sh.cvut.cz/pub/AfterStep/apps/asapm/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.tigr.net/afterstep/detail.pl?applet=asapm
COMMENT=		Laptop battery status display for X11

.if !exists(/usr/include/machine/apmvar.h)
IGNORE+=		"APM is not available for ${MACHINE_PLATFORM}"
.endif

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-jpeg	# there actually is no JPEG support
CONFIGURE_ARGS+=	--with-xpm
CONFIGURE_ARGS+=	--with-xpm-includes=${BUILDLINK_DIR}/include
CONFIGURE_ARGS+=	--with-xpm-library=${BUILDLINK_DIR}/lib

.include "../../mk/x11.buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
