# $NetBSD: Makefile,v 1.28 2015/07/04 16:18:35 joerg Exp $

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

.include "../../mk/bsd.pkg.mk"
