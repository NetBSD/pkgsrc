# $NetBSD: Makefile,v 1.6 2003/12/24 13:02:01 jmmv Exp $
#

DISTNAME=		dvipng-0.8
PKGREVISION=		2
CATEGORIES=		textproc converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=preview-latex/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://preview-latex.sourceforge.net/
COMMENT=		Convert DVI files to PNG files

USE_BUILDLINK2=		yes
USE_MAKEINFO=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INFO_FILES=		dvipng.info

BUILDLINK_DEPENDS.freetype2?=	freetype2>=2.1.3

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/gd/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../print/teTeX-bin/kpathsea.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
