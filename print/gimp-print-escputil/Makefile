# $NetBSD: Makefile,v 1.1.1.1 2002/02/15 20:49:24 drochner Exp $
#

DISTNAME=	gimp-print-4.2.0
PKGNAME=	gimp-print-escputil-4.2.0
CATEGORIES=	print
MASTER_SITES=	http://prdownloads.sourceforge.net/gimp-print/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gimp-print.sourceforge.net/
COMMENT=	Epson Stylus inkjet printer tool

BUILD_DEPENDS+=	gimp-print-lib-*:../../print/gimp-print-lib
CONFLICTS+=	gimp<=1.2.3

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --without-samples --without-user-guide
CONFIGURE_ARGS+= --without-gimp
CONFIGURE_ARGS+= --without-cups --without-translated-ppds
CONFIGURE_ARGS+= --enable-libgimpprint=no
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE= ${WRKSRC}/libtool
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
