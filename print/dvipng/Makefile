# $NetBSD: Makefile,v 1.25 2006/04/06 18:18:15 jlam Exp $

DISTNAME=	dvipng-1.7
CATEGORIES=	textproc converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dvipng/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dvipng.sourceforge.net/dvipng.html
COMMENT=	Convert DVI files to PNG files

CONFLICTS+=	teTeX-bin-[3-9].* teTeX-bin-[1-9][0-9]*

USE_TOOLS+=		makeinfo
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INFO_FILES=		# PLIST

BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.1.3

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
