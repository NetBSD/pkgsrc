# $NetBSD: Makefile,v 1.1.1.1 2003/04/23 08:15:40 rh Exp $
#

DISTNAME=		swfdec-0.2.1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=swfdec/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://swfdec.sourceforge.net/
COMMENT=		library for rendering Flash(R) animations and games

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/swfdec.pc.in

pre-install:
	echo "install:" >${WRKSRC}/plugin/Makefile

.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
