# $NetBSD: Makefile,v 1.6 2005/08/14 07:12:07 wulf Exp $
#

DISTNAME=	grig-0.4.3
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=groundstation/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=       http://groundstation.sourceforge.net/
COMMENT=	Graphical user interface to the Hamlib libraries

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
BUILD_USES_MSGFMT=  YES

.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
