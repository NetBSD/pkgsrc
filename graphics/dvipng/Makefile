# $NetBSD: Makefile,v 1.10.2.1 2010/05/17 22:47:51 tron Exp $

DISTNAME=	dvipng-1.12
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dvipng/}

MAINTAINER=	ahoka@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/dvipng/
COMMENT=	Convert TeX DVI files to PNG or GIF
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

BUILD_TARGET=	dvipng
INSTALL_TARGET=	install-dvigif

.include "../../fonts/t1lib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
