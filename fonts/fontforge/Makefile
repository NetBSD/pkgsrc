# $NetBSD: Makefile,v 1.8 2005/05/22 20:07:59 jlam Exp $

DISTNAME=	fontforge_full-${VERSION}
PKGNAME=	fontforge-${VERSION}
CATEGORIES=	fonts editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fontforge/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://fontforge.sourceforge.net/
COMMENT=	Postscript font editor

VERSION=	20050310

USE_TOOLS+=		gmake
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
