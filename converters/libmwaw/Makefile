# $NetBSD: Makefile,v 1.20 2019/07/01 04:07:45 ryoon Exp $

DISTNAME=	libmwaw-0.3.7
# next two lines added for 0.3.6-v2, remove after update to usual
# version number format
PKGNAME=	${DISTNAME:S/-v/./}
PKGREVISION=	9
WRKSRC=		${WRKDIR}/${DISTNAME:S/-v2//}
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libmwaw/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://sourceforge.net/p/libmwaw/wiki/Home/
COMMENT=	Import library for pre-OSX Mac text formats
LICENSE=	mpl-2.0 OR gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--without-docs

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CONFIGURE_ARGS+=	--with-sharedptr=c++11
.else
CONFIGURE_ARGS+=	--with-sharedptr=tr1
.endif

PKGCONFIG_OVERRIDE+=	libmwaw.pc.in

.include "../../converters/libwpg/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
