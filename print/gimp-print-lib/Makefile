# $NetBSD: Makefile,v 1.21 2004/03/02 14:56:07 drochner Exp $
#

DISTNAME=	gimp-print-4.2.6
PKGNAME=	gimp-print-lib-4.2.6
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gimp-print/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gimp-print.sourceforge.net/
COMMENT=	Drivers for Canon, Epson, Lexmark, and PCL printers

.if !exists(/usr/bin/flex) && !exists(/usr/bin/lex)
BUILD_DEPENDS+=		flex-[0-9]*:../../devel/flex
LEX=			${LOCALBASE}/bin/flex
.endif

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
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
