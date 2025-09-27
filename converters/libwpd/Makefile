# $NetBSD: Makefile,v 1.66 2025/09/27 09:57:10 wiz Exp $

DISTNAME=	libwpd-0.10.3
PKGREVISION=	11
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpd/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libwpd.sourceforge.net/
COMMENT=	Library for importing and exporting WordPerfect(tm) documents
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
USE_CXX_FEATURES+=	c++11
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-docs
PKGCONFIG_OVERRIDE+=	libwpd.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
