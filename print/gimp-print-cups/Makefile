# $NetBSD: Makefile,v 1.17 2004/10/03 00:18:04 tv Exp $
#

DISTNAME=	gimp-print-4.2.6
PKGNAME=	gimp-print-cups-4.2.6
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
USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	yes

.include "../../print/gimp-print-lib/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
