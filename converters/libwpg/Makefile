# $NetBSD: Makefile,v 1.46 2023/01/22 16:28:14 ryoon Exp $

DISTNAME=	libwpg-0.3.3
PKGREVISION=	9
CATEGORIES=	converters graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpg/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libwpg.sourceforge.net/
COMMENT=	Library for importing and converting Corel WordPerfect Graphics images
LICENSE=	gnu-lgpl-v2 OR mpl-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl pkg-config

# C++11
GCC_REQD+=	4.7

CONFIGURE_ARGS+=	--without-docs

PKGCONFIG_OVERRIDE+=	libwpg.pc.in

REPLACE_PERL=		src/conv/svg/wpg2svgbatch.pl

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
