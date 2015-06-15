# $NetBSD: Makefile,v 1.24 2015/06/15 09:57:21 markd Exp $

DISTNAME=	dvipng-1.15
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dvipng/} \
		http://download.savannah.gnu.org/releases/dvipng/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/dvipng/
COMMENT=	Convert TeX DVI files to PNG or GIF
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=		yes
CFLAGS+=	-I${BUILDLINK_PREFIX.kpathsea}/lib

BUILD_TARGET=		dvipng
INSTALL_TARGET=		install-dvigif

.include "../../fonts/t1lib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
