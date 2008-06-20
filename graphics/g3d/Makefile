# $NetBSD: Makefile,v 1.25 2008/06/20 01:09:21 joerg Exp $
#

DISTNAME=	g3d-0.0.2
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	3D modeller with a view of 3D modelling

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/g3d
USE_DIRS+=	xdg-1.1
USE_LIBTOOL=	YES
USE_TOOLS+=	gmake
USE_X11BASE=	YES
GNU_CONFIGURE=	YES

post-configure:
	@${LN} -s ${WRKSRC}/b3d/src ${WRKSRC}/g3d/b3d

.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtkglarea/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
