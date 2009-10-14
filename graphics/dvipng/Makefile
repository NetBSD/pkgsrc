# $NetBSD: Makefile,v 1.8 2009/10/14 07:22:46 tron Exp $

DISTNAME=	dvipng-1.11
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dvipng/}

MAINTAINER=	ahoka@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/dvipng/
COMMENT=	Convert TeX DVI files to PNG or GIF

DEPENDS+=	teTeX-bin>=3.0nb27:../../print/teTeX3-bin

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
INFO_FILES=		yes
USE_TOOLS+=		makeinfo

.include "../../mk/bsd.prefs.mk"

# DragonFly has stripped makeinfo in the base - without texi2dvi.
.if ${OPSYS} == "DragonFly"
BUILD_DEPENDS+=		gtexinfo-[0-9]*:../../devel/gtexinfo
.endif

.include "../../fonts/t1lib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
