# $NetBSD: Makefile,v 1.12 2005/04/11 21:45:02 tv Exp $
#

DISTNAME=	transcalc-0.14
CATEGORIES=	cad
MASTER_SITES=	http://transcalc.sourceforge.net/
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=transcalc/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://transcalc.sourceforge.net/
COMMENT=	Transmission line analysis/synthesis

GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
#.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
