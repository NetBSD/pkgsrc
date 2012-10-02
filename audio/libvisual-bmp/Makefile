# $NetBSD: Makefile,v 1.31 2012/10/02 17:10:33 tron Exp $
#

DISTNAME=		libvisual-bmp-0.2.0
PKGREVISION=		19
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libvisual/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://localhost.nl/~synap/libvisual-wiki/
COMMENT=		Libvisual Beep Media Player plugin

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config msgfmt

post-extract:
	${MV} ${WRKSRC}/pixmaps/libvisual-xmms-vis.bmp \
		${WRKSRC}/pixmaps/libvisual-bmp-vis.bmp
	${MV} ${WRKSRC}/pixmaps/libvisual-xmms-vis.xpm \
		${WRKSRC}/pixmaps/libvisual-bmp-vis.xpm

.include "../../audio/bmp/buildlink3.mk"
.include "../../audio/libvisual0.2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
