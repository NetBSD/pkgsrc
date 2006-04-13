# $NetBSD: Makefile,v 1.11 2006/04/13 18:23:34 jlam Exp $
#

DISTNAME=	grig-0.4.3
PKGREVISION=	3
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=groundstation/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=       http://groundstation.sourceforge.net/
COMMENT=	Graphical user interface to the Hamlib libraries

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake msgfmt
GNU_CONFIGURE=	yes

.include "../../ham/hamlib/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
