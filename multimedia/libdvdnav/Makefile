# $NetBSD: Makefile,v 1.9 2012/01/20 18:13:58 drochner Exp $
#

DISTNAME=	libdvdnav-4.2.0
CATEGORIES=	multimedia
MASTER_SITES=	http://dvdnav.mplayerhq.hu/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dvdnav.mplayerhq.hu/
COMMENT=	Library to navigate DVDs

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		automake autoconf aclocal autoreconf

pre-configure:
	cd ${WRKSRC} && autoreconf -vi

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
