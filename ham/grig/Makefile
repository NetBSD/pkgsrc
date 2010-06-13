# $NetBSD: Makefile,v 1.19 2010/06/13 22:44:48 wiz Exp $
#

DISTNAME=	grig-0.7.2
PKGREVISION=	2
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=groundstation/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://groundstation.sourceforge.net/
COMMENT=	Graphical user interface to the Hamlib libraries

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config
GNU_CONFIGURE=	yes

.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
