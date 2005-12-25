# $NetBSD: Makefile,v 1.14 2005/12/25 16:52:55 jschauma Exp $

DISTNAME=	libpixman-0.1.6
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://cairographics.org/
COMMENT=	Pixel manipulation library

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libpixman.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mmipspro*)
CFLAGS+=		-c99
.endif

.include "../../mk/bsd.pkg.mk"
