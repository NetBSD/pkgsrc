# $NetBSD: Makefile,v 1.2 2002/03/13 17:37:35 fredb Exp $
#

DISTNAME=	gimp-print-4.2.0
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://prdownloads.sourceforge.net/gimp-print/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gimp-print.sourceforge.net/
COMMENT=	GIMP print plugin

DEPENDS+=	gimp-print-lib-*:../../print/gimp-print-lib
CONFLICTS+=	gimp<=1.2.3

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --without-samples --without-user-guide
CONFIGURE_ARGS+= --without-cups --without-translated-ppds
CONFIGURE_ARGS+= --enable-escputil=no
CONFIGURE_ARGS+= --enable-libgimpprint=no
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE= ${WRKSRC}/libtool
USE_GMAKE=	yes

.include "../../graphics/gimp-base/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
