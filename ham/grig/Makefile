# $NetBSD: Makefile,v 1.15 2006/12/27 05:57:25 wulf Exp $
#

DISTNAME=	grig-0.7.2
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=groundstation/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=       http://groundstation.sourceforge.net/
COMMENT=	Graphical user interface to the Hamlib libraries

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config
GNU_CONFIGURE=	yes

.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
