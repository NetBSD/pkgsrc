# $NetBSD: Makefile,v 1.7 2012/10/03 00:20:12 asau Exp $

DISTNAME=	libwpg-0.2.0
CATEGORIES=	converters graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpg/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libwpg.sourceforge.net/
COMMENT=	Library for importing and converting Corel WordPerfect Graphics images
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		perl pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-docs
PKGCONFIG_OVERRIDE+=	libwpg-0.2.pc.in

REPLACE_PERL=		src/conv/svg/wpg2svgbatch.pl

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
BUILDLINK_TRANSFORM+=	rm:-Werror
.endif

.include "../../converters/libwpd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
