# $NetBSD: Makefile,v 1.1 2013/08/24 16:09:56 jaapb Exp $

DISTNAME=	libmwaw-0.1.10
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libmwaw/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://sourceforge.net/p/libmwaw/wiki/Home/
COMMENT=	Import library for pre-OSX Mac text formats
LICENSE=	mpl-2.0 OR gnu-lgpl-v2

WRKSRC=		${WRKDIR}/libmwaw-0.1.10
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++
CONFIGURE_ARGS+=	--with-sharedptr=tr1 --without-docs

PKGCONFIG_OVERRIDE+=	libmwaw.pc.in

.include "../../converters/libwpd/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
