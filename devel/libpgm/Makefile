# $NetBSD: Makefile,v 1.13 2022/06/28 11:31:47 wiz Exp $
#

DISTNAME=	libpgm-5.1.118
PKGREVISION=	10
CATEGORIES=	devel
MASTER_SITES=	http://openpgm.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://code.google.com/archive/p/openpgm/
COMMENT=	PGM reliable multicast library implementing RFC 3208
LICENSE=	gnu-lgpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME}/openpgm/pgm

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl

post-configure:
	cd ${WRKSRC} && ${SH} mkversion

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
