# $NetBSD: Makefile,v 1.8 2001/05/08 19:48:45 dmcmahill Exp $

DISTNAME=	dx-4.1.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.research.ibm.com/dx/srcDownload/srcArchive/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.research.ibm.com/dx/
COMMENT=	Open Visualization Data Explorer

DEPENDS+=	jpeg-6b:../../graphics/jpeg

USE_MOTIF=	yes
USE_MESA=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

#override ARCH to avoid picking up a bad ${ARCH} during the build
MAKE_ENV+=	ARCH=""
CONFIGURE_ENV+=	ARCH=""

.include "../../mk/bsd.pkg.mk"
