# $NetBSD: Makefile,v 1.1.1.1 2002/02/15 20:46:27 drochner Exp $
#

DISTNAME=	gimp-print-4.2.0
PKGNAME=	gimp-print-lib-4.2.0
CATEGORIES=	print
MASTER_SITES=	http://prdownloads.sourceforge.net/gimp-print/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gimp-print.sourceforge.net/
COMMENT=	drivers for Canon, Epson, Lexmark, and PCL printers

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --without-gimp --without-translated-ppds --without-samples
CONFIGURE_ARGS+= --enable-escputil=no
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE= ${WRKSRC}/libtool
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
