# $NetBSD: Makefile,v 1.1.1.1 2002/05/03 12:45:21 drochner Exp $
#

DISTNAME=	gimp-print-4.2.1
PKGNAME=	gimp-print-cups-4.2.1
CATEGORIES=	print
MASTER_SITES=	http://prdownloads.sourceforge.net/gimp-print/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gimp-print.sourceforge.net/
COMMENT=	GIMP print plugin

DEPENDS+=	gimp-print-lib-*:../../print/gimp-print-lib

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --without-samples --without-user-guide
CONFIGURE_ARGS+= --without-gimp
CONFIGURE_ARGS+= --with-cups=${PREFIX}
CONFIGURE_ARGS+= --without-translated-ppds
CONFIGURE_ARGS+= --enable-escputil=no
CONFIGURE_ARGS+= --enable-libgimpprint=no
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE= ${WRKSRC}/libtool
USE_GMAKE=	yes

.include "../../print/cups/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
