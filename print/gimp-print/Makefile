# $NetBSD: Makefile,v 1.16 2004/01/24 14:58:00 grant Exp $
#

DISTNAME=	gimp-print-4.2.5
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gimp-print/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gimp-print.sourceforge.net/
COMMENT=	GIMP print plugin

CONFLICTS+=	gimp<=1.2.3

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --without-samples --without-user-guide
CONFIGURE_ARGS+= --without-cups --without-translated-ppds
CONFIGURE_ARGS+= --enable-escputil=no
CONFIGURE_ARGS+= --enable-libgimpprint=no
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE= ${WRKSRC}/libtool
USE_GNU_TOOLS+=	make
USE_BUILDLINK2=	yes
USE_X11=	yes

.include "../../print/gimp-print-lib/buildlink2.mk"
.include "../../graphics/gimp-base/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
