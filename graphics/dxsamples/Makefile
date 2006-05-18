# $NetBSD: Makefile,v 1.21 2006/05/18 20:29:59 wiz Exp $

DISTNAME=	dxsamples-4.3.2
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://opendx.npaci.edu/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.research.ibm.com/dx/
COMMENT=	Sample data for Open Visualization Data Explorer

BROKEN_IN=	pkgsrc-2005Q4 pkgsrc-2006Q1

DEPENDS+=	dx-[0-9]*:../../graphics/dx

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_X11BASE=	yes

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
