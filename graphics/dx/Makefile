# $NetBSD: Makefile,v 1.5 2000/04/28 15:27:00 drochner Exp $

DISTNAME=	dx-4.1.0
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
