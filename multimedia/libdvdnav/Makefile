# $NetBSD: Makefile,v 1.10 2012/10/08 09:21:06 asau Exp $
#

DISTNAME=	libdvdnav-4.2.0
CATEGORIES=	multimedia
MASTER_SITES=	http://dvdnav.mplayerhq.hu/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dvdnav.mplayerhq.hu/
COMMENT=	Library to navigate DVDs

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		automake autoconf aclocal autoreconf

pre-configure:
	cd ${WRKSRC} && autoreconf -vi

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
