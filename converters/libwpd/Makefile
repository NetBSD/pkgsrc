# $NetBSD: Makefile,v 1.52 2020/03/25 10:00:43 nia Exp $

DISTNAME=	libwpd-0.10.3
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpd/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://libwpd.sourceforge.net/
COMMENT=	Library for importing and exporting WordPerfect(tm) documents
LICENSE=	gnu-lgpl-v2.1

# C++11
GCC_REQD+=	4.7

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-docs
PKGCONFIG_OVERRIDE+=	libwpd.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
