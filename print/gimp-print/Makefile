# $NetBSD: Makefile,v 1.21 2004/09/27 11:53:10 adam Exp $

DISTNAME=	gimp-print-4.2.7
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gimp-print/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gimp-print.sourceforge.net/
COMMENT=	GIMP print plugin

CONFLICTS+=	gimp<=1.2.3

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-samples --without-user-guide
CONFIGURE_ARGS+=	--without-cups --without-translated-ppds
CONFIGURE_ARGS+=	--enable-escputil=no --enable-libgimpprint=no

.include "../../print/gimp-print-lib/buildlink3.mk"
.include "../../graphics/gimp1-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
