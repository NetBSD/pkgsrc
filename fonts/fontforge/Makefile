# $NetBSD: Makefile,v 1.5 2005/02/15 14:39:11 adam Exp $

DISTNAME=	fontforge_full-${VERSION}
PKGNAME=	fontforge-${VERSION}
CATEGORIES=	fonts editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fontforge/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://fontforge.sourceforge.net/
COMMENT=	Postscript font editor

VERSION=	20050209

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-freetype-src=no
WRKSRC=			${WRKDIR}/fontforge-${VERSION}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
