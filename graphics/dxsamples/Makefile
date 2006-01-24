# $NetBSD: Makefile,v 1.18 2006/01/24 07:32:11 wiz Exp $

DISTNAME=	dxsamples-4.3.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://opendx.npaci.edu/source/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.research.ibm.com/dx/
COMMENT=	Sample data for Open Visualization Data Explorer

BROKEN_IN=	pkgsrc-2005Q4

DEPENDS+=	dx-[0-9]*:../../graphics/dx

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_X11BASE=	yes

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
