# $NetBSD: Makefile,v 1.21 2014/05/05 00:47:45 ryoon Exp $
#

DISTNAME=	libview-0.6.4
PKGREVISION=	19
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=view/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://view.sourceforge.net/
COMMENT=	GTK+ widget collection
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libview.pc.in

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
