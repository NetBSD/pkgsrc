# $NetBSD: Makefile,v 1.37 2023/05/22 11:39:00 wiz Exp $

DISTNAME=	dvipng-1.15
PKGREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dvipng/}
MASTER_SITES+=	https://download.savannah.gnu.org/releases/dvipng/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/dvipng/
COMMENT=	Convert TeX DVI files to PNG or GIF
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
CFLAGS+=	-I${BUILDLINK_PREFIX.kpathsea}/lib

BUILD_TARGET=		dvipng
INSTALL_TARGET=		install-dvigif

.include "../../fonts/t1lib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
