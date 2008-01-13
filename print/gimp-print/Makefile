# $NetBSD: Makefile,v 1.30 2008/01/13 01:20:28 gdt Exp $

DISTNAME=	gimp-print-4.2.7
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gimp-print/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://gimp-print.sourceforge.net/
COMMENT=	GIMP print plugin

CONFLICTS+=	gimp<=1.2.3

USE_TOOLS+=		gmake lex
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-samples --without-user-guide
CONFIGURE_ARGS+=	--without-cups --without-translated-ppds
CONFIGURE_ARGS+=	--enable-escputil=no --enable-libgimpprint=no

.include "../../print/gimp-print-lib/buildlink3.mk"
.include "../../graphics/gimp1-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
