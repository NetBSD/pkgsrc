# $NetBSD: Makefile,v 1.2 1999/10/27 17:14:08 agc Exp $

DISTNAME=	dx-4.0.7
CATEGORIES=	graphics
MASTER_SITES=	http://www.research.ibm.com/dx/srcDownload/srcArchive/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.research.ibm.com/dx/

BROKEN=		Compilation problems

DEPENDS+=	Mesa-*:../../graphics/Mesa
DEPENDS+=	jpeg-6b:../../graphics/jpeg

USE_MOTIF=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
