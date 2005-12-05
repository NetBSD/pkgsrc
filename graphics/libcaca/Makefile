# $NetBSD: Makefile,v 1.11 2005/12/05 20:50:21 rillig Exp $
#

DISTNAME=	libcaca-0.9
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://sam.zoy.org/projects/libcaca/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://sam.zoy.org/projects/libcaca/
COMMENT=	Graphics library that outputs text instead of pixels, in colour

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INCOMPAT_CURSES=	NetBSD-1.5*-* NetBSD-1.6[-_.]*-* NetBSD-1.6[A-Q]-*

.include "options.mk"

CONFIGURE_ARGS+=	--disable-doc

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
LDFLAGS+=	-ldl
.endif

.include "../../mk/bsd.pkg.mk"
