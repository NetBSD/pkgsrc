# $NetBSD: Makefile,v 1.14 2005/10/04 12:47:02 adam Exp $

DISTNAME=	fontforge_full-${VERSION}
PKGNAME=	fontforge-${VERSION}
CATEGORIES=	fonts editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fontforge/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://fontforge.sourceforge.net/
COMMENT=	Postscript font editor

VERSION=	20050919

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-freetype-src
WRKSRC=			${WRKDIR}/${PKGNAME}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
