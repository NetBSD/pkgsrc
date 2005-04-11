# $NetBSD: Makefile,v 1.9 2005/04/11 21:46:05 tv Exp $
#

DISTNAME=		libcaca-0.9
PKGREVISION=	1
CATEGORIES=		graphics
MASTER_SITES=		http://sam.zoy.org/projects/libcaca/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://sam.zoy.org/projects/libcaca/
COMMENT=		Graphics library that outputs text instead of pixels, in colour

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INCOMPAT_CURSES=	NetBSD-1.5* NetBSD-1.6[-_.]* NetBSD-1.6[A-Q]-*

CONFIGURE_ARGS+=	--disable-slang --enable-ncurses --disable-imlib2 --disable-doc

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
LDFLAGS=	-ldl
.endif

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
