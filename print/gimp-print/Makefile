# $NetBSD: Makefile,v 1.5 2002/05/03 13:52:14 wiz Exp $
#

DISTNAME=	gimp-print-4.2.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gimp-print/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gimp-print.sourceforge.net/
COMMENT=	GIMP print plugin

DEPENDS+=	gimp-print-lib>=4.2.1:../../print/gimp-print-lib
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
