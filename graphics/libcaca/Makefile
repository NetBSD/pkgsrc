# $NetBSD: Makefile,v 1.6 2004/08/15 12:40:07 wiz Exp $
#

DISTNAME=		libcaca-0.9
CATEGORIES=		graphics
MASTER_SITES=		http://sam.zoy.org/projects/libcaca/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://sam.zoy.org/projects/libcaca/
COMMENT=		Graphics library that outputs text instead of pixels, in colour

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-slang --enable-ncurses --disable-imlib2 --disable-doc

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
LDFLAGS=	-ldl
.endif

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
