# $NetBSD: Makefile,v 1.23 2013/05/10 07:13:59 adam Exp $

DISTNAME=	libdvdread-4.2.0
CATEGORIES=	multimedia
MASTER_SITES=	http://dvdnav.mplayerhq.hu/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dvdnav.mplayerhq.hu/
COMMENT=	DVD access library
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoconf automake autoreconf gmake
GNU_CONFIGURE=		yes

MESSAGE_SUBST+=		PKGBASE=${PKGBASE}

pre-configure:
	cd ${WRKSRC} && autoreconf -vi

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
