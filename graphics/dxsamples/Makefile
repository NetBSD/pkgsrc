# $NetBSD: Makefile,v 1.3 2000/01/02 03:38:32 wiz Exp $

DISTNAME=	dxsamples-4.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.research.ibm.com/dx/srcDownload/srcArchive/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.research.ibm.com/dx/

DEPENDS+=	dx-*:../../graphics/dx

BROKEN=		pre-requisite of dx, which is broken

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X11BASE=	yes

.include "../../mk/bsd.pkg.mk"
