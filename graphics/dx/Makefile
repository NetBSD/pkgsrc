# $NetBSD: Makefile,v 1.3 2000/01/02 03:38:31 wiz Exp $

DISTNAME=	dx-4.0.7
CATEGORIES=	graphics
MASTER_SITES=	http://www.research.ibm.com/dx/srcDownload/srcArchive/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.research.ibm.com/dx/

DEPENDS+=	Mesa-*:../../graphics/Mesa
DEPENDS+=	jpeg-6b:../../graphics/jpeg

BROKEN=		Compilation problems

USE_MOTIF=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
