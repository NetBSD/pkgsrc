# $NetBSD: Makefile,v 1.22 2004/03/11 20:45:16 reed Exp $
#

DISTNAME=	gimp-print-4.2.6
PKGNAME=	gimp-print-lib-4.2.6
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gimp-print/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gimp-print.sourceforge.net/
COMMENT=	Drivers for Canon, Epson, Lexmark, and PCL printers

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make lex
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
INFO_FILES=		gimpprint.info

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-cups
CONFIGURE_ARGS+=	--without-ghost
CONFIGURE_ARGS+=	--without-gimp
CONFIGURE_ARGS+=	--without-readline
CONFIGURE_ARGS+=	--without-translated-ppds
CONFIGURE_ARGS+=	--without-samples
CONFIGURE_ARGS+=	--disable-escputil

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
