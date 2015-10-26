# $NetBSD: Makefile,v 1.5 2015/10/26 05:52:06 agc Exp $
#

DISTNAME=	dieharder-3.31.1
CATEGORIES=	math
MASTER_SITES=	http://www.phy.duke.edu/~rgb/General/dieharder/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.phy.duke.edu/~rgb/General/dieharder.php
COMMENT=	Random number generator test suite
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

AUTOMAKE_REQD=	1.9.6
USE_TOOLS+=	automake gmake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
MANCOMPRESSED=	yes
AUTO_MKDIRS=	yes

pre-configure:
	cd ${WRKSRC}; ${SH} ./autogen.sh

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
