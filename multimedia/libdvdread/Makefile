# $NetBSD: Makefile,v 1.26 2014/10/04 12:43:39 wiz Exp $

DISTNAME=	libdvdread-5.0.0
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.videolan.org/pub/videolan/libdvdread/5.0.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dvdnav.mplayerhq.hu/
COMMENT=	DVD access library
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	misc/dvdread.pc.in

MESSAGE_SUBST+=		PKGBASE=${PKGBASE}

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
