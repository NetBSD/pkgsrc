# $NetBSD: Makefile,v 1.3 2002/02/18 13:28:44 tron Exp $
#

DISTNAME=	gimp-print-4.2.0
PKGNAME=	gimp-print-lib-4.2.0
CATEGORIES=	print
MASTER_SITES=	http://prdownloads.sourceforge.net/gimp-print/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gimp-print.sourceforge.net/
COMMENT=	drivers for Canon, Epson, Lexmark, and PCL printers

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-cups
CONFIGURE_ARGS+=	--without-ghost
CONFIGURE_ARGS+=	--without-gimp
CONFIGURE_ARGS+=	--without-readline
CONFIGURE_ARGS+=	--without-translated-ppds
CONFIGURE_ARGS+=	--without-samples
CONFIGURE_ARGS+=	--disable-escputil

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
