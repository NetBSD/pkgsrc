# $NetBSD: Makefile,v 1.19 2009/01/14 22:28:05 jmcneill Exp $

DISTNAME=	libdvdread-4.1.3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.mplayerhq.hu/MPlayer/releases/dvdnav/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mplayerhq.hu/
COMMENT=	DVD access library

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake autoconf automake aclocal autoreconf
USE_LIBTOOL=	yes

MESSAGE_SUBST+=	PKGBASE=${PKGBASE:Q}

pre-configure:
	cd ${WRKSRC} && autoreconf -vi

.include "../../mk/bsd.pkg.mk"
