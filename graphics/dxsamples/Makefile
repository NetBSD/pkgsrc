# $NetBSD: Makefile,v 1.24 2006/10/13 16:40:10 drochner Exp $

DISTNAME=	dxsamples-4.4.0
CATEGORIES=	graphics
MASTER_SITES=	http://opendx.npaci.edu/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.research.ibm.com/dx/
COMMENT=	Sample data for Open Visualization Data Explorer

DEPENDS+=	dx-[0-9]*:../../graphics/dx

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake makeinfo
CONFIGURE_ARGS+=	MAKEINFO=${TOOLS_PATH.makeinfo}
USE_X11BASE=	yes

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
