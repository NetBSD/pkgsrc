# $NetBSD: Makefile,v 1.14 2009/08/26 19:58:03 sno Exp $

DISTNAME=	qbrew-0.3.5
PKGREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	http://www.usermode.org/code/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.usermode.org/code.html
COMMENT=	Homebrewer's recipe calculator

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
