# $NetBSD: Makefile,v 1.1.1.1 2003/12/21 21:25:57 wiz Exp $
#

DISTNAME=		libcaca-0.3
CATEGORIES=		graphics
MASTER_SITES=		http://sam.zoy.org/projects/libcaca/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://sam.zoy.org/projects/libcaca/
COMMENT=		Graphics library that outputs text instead of pixels, in colour

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-slang --disable-ncurses

.include "../../devel/libslang/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
