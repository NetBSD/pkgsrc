# $NetBSD: Makefile,v 1.7 2003/06/02 01:17:30 jschauma Exp $
#

DISTNAME=	gimp-print-4.2.5
PKGNAME=	gimp-print-cups-4.2.5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gimp-print/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://gimp-print.sourceforge.net/
COMMENT=	GIMP print plugin

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
USE_BUILDLINK2=	yes

.include "../../print/gimp-print-lib/buildlink2.mk"
.include "../../print/cups/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
