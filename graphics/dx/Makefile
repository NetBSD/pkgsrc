# $NetBSD: Makefile,v 1.4 2000/01/31 20:56:49 drochner Exp $

DISTNAME=	dx-4.0.10
CATEGORIES=	graphics
MASTER_SITES=	http://www.research.ibm.com/dx/srcDownload/srcArchive/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.research.ibm.com/dx/

DEPENDS+=	Mesa-*:../../graphics/Mesa
DEPENDS+=	jpeg-6b:../../graphics/jpeg

USE_MOTIF=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
