# $NetBSD: Makefile,v 1.2 2013/10/30 15:22:36 pettai Exp $

DISTNAME=	sleuthkit-3.2.3
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

REPLACE_PERL=	tools/timeline/mactime tools/sorter/sorter

.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
