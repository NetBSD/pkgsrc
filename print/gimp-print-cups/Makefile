# $NetBSD: Makefile,v 1.11 2004/01/24 14:58:00 grant Exp $
#

DISTNAME=	gimp-print-4.2.5
PKGNAME=	gimp-print-cups-4.2.5
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gimp-print/}

MAINTAINER=	tech-pkg@NetBSD.org
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
USE_GNU_TOOLS+=	make
USE_BUILDLINK2=	yes

.include "../../print/gimp-print-lib/buildlink2.mk"
.include "../../print/cups/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
