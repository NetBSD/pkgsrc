# $NetBSD: Makefile,v 1.91 2014/05/05 00:47:51 ryoon Exp $

DISTNAME=	fontforge_full-20120731-b
PKGNAME=	${DISTNAME:S/_full//:S/-b//}
PKGREVISION=	8
CATEGORIES=	fonts editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fontforge/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://fontforge.sourceforge.net/
COMMENT=	Postscript font editor
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}/${DISTNAME:S/_full//}

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-freetype-src
CONFIGURE_ARGS+=	--without-python

MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
LDFLAGS.SunOS+=		-lrt

BROKEN_GETTEXT_DETECTION=	yes

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
