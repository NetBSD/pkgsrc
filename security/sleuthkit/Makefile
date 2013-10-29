# $NetBSD: Makefile,v 1.1 2013/10/29 23:33:02 pettai Exp $

DISTNAME=	sleuthkit-3.2.3
CATEGORIES=	security
MASTER_SITES=	https://github.com/sleuthkit/sleuthkit/archive/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.sleuthkit.org/
COMMENT=	The Sleuth Kit (TSK)
LICENSE=	cpl-1.0 AND gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	perl:run

REPLACE_PERL=	tools/timeline/mactime tools/sorter/sorter

.include "../../mk/bsd.pkg.mk"
