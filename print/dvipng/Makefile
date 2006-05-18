# $NetBSD: Makefile,v 1.27 2006/05/18 20:25:17 wiz Exp $

DISTNAME=	dvipng-1.7
PKGREVISION=	1
CATEGORIES=	textproc converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dvipng/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dvipng.sourceforge.net/dvipng.html
COMMENT=	Convert DVI files to PNG files

TEX_ACCEPTED=	teTeX2

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
