# $NetBSD: Makefile,v 1.2 2004/10/03 00:14:59 tv Exp $
#

DISTNAME=	grig-0.2.2
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=groundstation/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=       http://groundstation.sourceforge.net/
COMMENT=	Graphical user interface to the Hamlib libraries

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes
BUILD_USES_MSGFMT=  YES

CPPFLAGS=	-DHAMLIB_CVS=1

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gal/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
