# $NetBSD: Makefile,v 1.3 2003/12/26 09:38:52 jmmv Exp $
#

DISTNAME=		libcaca-0.5
CATEGORIES=		graphics
MASTER_SITES=		http://sam.zoy.org/projects/libcaca/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://sam.zoy.org/projects/libcaca/
COMMENT=		Graphics library that outputs text instead of pixels, in colour

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-slang --disable-ncurses

.include "../../devel/libslang/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
