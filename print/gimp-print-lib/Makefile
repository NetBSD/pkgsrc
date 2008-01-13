# $NetBSD: Makefile,v 1.32 2008/01/13 01:20:29 gdt Exp $

DISTNAME=	gimp-print-4.2.7
PKGNAME=	gimp-print-lib-4.2.7
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gimp-print/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://gimp-print.sourceforge.net/
COMMENT=	Drivers for Canon, Epson, Lexmark, and PCL printers

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake lex
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
INFO_FILES=		# PLIST

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-cups
CONFIGURE_ARGS+=	--without-ghost
CONFIGURE_ARGS+=	--without-gimp
CONFIGURE_ARGS+=	--without-readline
CONFIGURE_ARGS+=	--without-translated-ppds
CONFIGURE_ARGS+=	--without-samples
CONFIGURE_ARGS+=	--disable-escputil

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
