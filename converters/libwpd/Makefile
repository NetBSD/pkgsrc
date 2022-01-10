# $NetBSD: Makefile,v 1.58 2022/01/10 01:46:26 ryoon Exp $

DISTNAME=	libwpd-0.10.3
PKGREVISION=	5
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpd/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://libwpd.sourceforge.net/
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
