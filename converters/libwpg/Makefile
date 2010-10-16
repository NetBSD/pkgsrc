# $NetBSD: Makefile,v 1.1.1.1 2010/10/16 15:26:34 wiz Exp $

DISTNAME=	libwpg-0.1.3
CATEGORIES=	converters graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libwpg.sourceforge.net/
COMMENT=	Library for importing and converting Corel WordPerfect Graphics images
#LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-docs
PKGCONFIG_OVERRIDE+=	libwpg-0.1.pc.in libwpg-stream-0.1.pc.in

REPLACE_PERL=		src/conv/svg/wpg2svgbatch.pl

.include "../../converters/libwpd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
