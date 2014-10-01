# $NetBSD: Makefile,v 1.24 2014/10/01 12:18:19 wiz Exp $

DISTNAME=	libdvdread-5.0.0
CATEGORIES=	multimedia
MASTER_SITES=	http://www.videolan.org/pub/videolan/libdvdread/5.0.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dvdnav.mplayerhq.hu/
COMMENT=	DVD access library
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
#USE_TOOLS+=		aclocal autoconf automake autoreconf gmake
GNU_CONFIGURE=		yes

MESSAGE_SUBST+=		PKGBASE=${PKGBASE}

#pre-configure:
#	cd ${WRKSRC} && autoreconf -vi

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
