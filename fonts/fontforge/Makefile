# $NetBSD: Makefile,v 1.1.1.1 2004/11/29 10:03:33 adam Exp $

DISTNAME=	fontforge_full-${VERSION}
PKGNAME=	fontforge-${VERSION}
CATEGORIES=	fonts editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fontforge/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://fontforge.sourceforge.net/
COMMENT=	Postscript font editor

VERSION=	20041115

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-freetype-src=no
WRKSRC=			${WRKDIR}/fontforge-${VERSION}

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
