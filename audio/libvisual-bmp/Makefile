# $NetBSD: Makefile,v 1.1.1.1 2004/11/05 21:12:35 wiz Exp $
#

DISTNAME=		libvisual-bmp-0.1.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libvisual/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://libvisual.sourceforge.net/
COMMENT=		Libvisual Beep Media Player plugin

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

post-extract:
	${MV} ${WRKSRC}/pixmaps/libvisual-xmms-vis.bmp \
		${WRKSRC}/pixmaps/libvisual-bmp-vis.bmp
	${MV} ${WRKSRC}/pixmaps/libvisual-xmms-vis.xpm \
		${WRKSRC}/pixmaps/libvisual-bmp-vis.xpm

.include "../../audio/bmp/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../zzz/libvisual/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
