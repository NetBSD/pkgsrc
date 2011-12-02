# $NetBSD: Makefile,v 1.1.1.1 2011/12/02 05:25:12 agc Exp $
#

DISTNAME=	libpgm-5.1.118
CATEGORIES=	devel
MASTER_SITES=	http://openpgm.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://code.google.com/p/openpgm/
COMMENT=	PGM reliable multicast library implementing RFC 3208
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}/openpgm/pgm

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl

post-configure:
	cd ${WRKSRC} && ${SH} mkversion

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
