# $NetBSD: Makefile,v 1.22 2006/06/11 13:27:20 joerg Exp $

DISTNAME=	dxsamples-4.3.2
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://opendx.npaci.edu/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.research.ibm.com/dx/
COMMENT=	Sample data for Open Visualization Data Explorer

BROKEN_IN=	pkgsrc-2005Q4 pkgsrc-2006Q1

DEPENDS+=	dx-[0-9]*:../../graphics/dx

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake makeinfo
CONFIGURE_ARGS+=	MAKEINFO=${TOOLS_PATH.makeinfo}
USE_X11BASE=	yes

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
