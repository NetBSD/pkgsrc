# $NetBSD: Makefile,v 1.11 2003/05/07 22:04:30 seb Exp $
#

DISTNAME=	gimp-print-4.2.5
PKGNAME=	gimp-print-lib-4.2.5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gimp-print/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gimp-print.sourceforge.net/
COMMENT=	drivers for Canon, Epson, Lexmark, and PCL printers

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
TEXINFO_OVERRIDE=	YES

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-cups
CONFIGURE_ARGS+=	--without-ghost
CONFIGURE_ARGS+=	--without-gimp
CONFIGURE_ARGS+=	--without-readline
CONFIGURE_ARGS+=	--without-translated-ppds
CONFIGURE_ARGS+=	--without-samples
CONFIGURE_ARGS+=	--disable-escputil

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
