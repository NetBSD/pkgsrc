# $NetBSD: Makefile,v 1.14 2005/03/23 21:59:32 wiz Exp $

DISTNAME=	dvipng-1.0
PKGREVISION=	2
CATEGORIES=	textproc converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dvipng/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://dvipng.sourceforge.net/dvipng.html
COMMENT=	Convert DVI files to PNG files

USE_BUILDLINK3=		yes
USE_MAKEINFO=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INFO_FILES=		dvipng.info

BUILDLINK_DEPENDS.freetype2?=	freetype2>=2.1.3

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/teTeX-bin/kpathsea.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
