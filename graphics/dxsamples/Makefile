# $NetBSD: Makefile,v 1.2 1999/10/27 17:14:08 agc Exp $

DISTNAME=	dxsamples-4.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.research.ibm.com/dx/srcDownload/srcArchive/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.research.ibm.com/dx/

BROKEN=		pre-requisite of dx, which is broken

DEPENDS+=	dx-*:../../graphics/dx

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X11BASE=	yes

.include "../../mk/bsd.pkg.mk"
