# $NetBSD: Makefile,v 1.1.1.1 2004/01/13 11:25:36 jmmv Exp $
#

DISTNAME=	xawtv_3.90
PKGNAME=	${DISTNAME:S/_/-/}
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	graphics
MASTER_SITES=	http://bytesex.org/xawtv/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://bytesex.org/xawtv/
COMMENT=	TV application for Brooktree 848 compatible cards

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_X11=		YES

CONFIGURE_ARGS+=	--disable-aalib
CONFIGURE_ARGS+=	--disable-motif

LDFLAGS+=		${LIBOSSAUDIO}

.include "../../mk/bsd.prefs.mk"

.if defined(USE_MMX) && !empty(USE_MMX:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-mmx
.endif

.include "../../devel/ncurses/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../x11/Xaw3d/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
