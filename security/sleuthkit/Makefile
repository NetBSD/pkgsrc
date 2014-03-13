# $NetBSD: Makefile,v 1.3 2014/03/13 23:41:31 pettai Exp $

DISTNAME=	sleuthkit-4.1.3
CATEGORIES=	security sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sleuthkit/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.sleuthkit.org/
COMMENT=	The Sleuth Kit (TSK) opensource forensic toolkit
LICENSE=	cpl-1.0 AND gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake file perl:run

.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
