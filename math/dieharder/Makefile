# $NetBSD: Makefile,v 1.4 2012/09/11 23:04:18 asau Exp $
#

DISTNAME=	dieharder-2.24.4
CATEGORIES=	math
MASTER_SITES=	http://www.phy.duke.edu/~rgb/General/dieharder/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.phy.duke.edu/~rgb/General/dieharder.php
COMMENT=	Random number generator test suite

MAKE_JOBS_SAFE=		no

AUTOMAKE_REQD=	1.9.6
USE_TOOLS+=	automake gmake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
MANCOMPRESSED=	yes

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

pre-configure:
	cd ${WRKSRC}; ${SH} ./autogen.sh

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
