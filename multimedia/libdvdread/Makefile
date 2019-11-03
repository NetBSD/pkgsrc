# $NetBSD: Makefile,v 1.31 2019/11/03 11:06:55 adam Exp $

DISTNAME=	libdvdread-6.0.2
CATEGORIES=	multimedia
MASTER_SITES=	http://download.videolan.org/pub/videolan/libdvdread/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dvdnav.mplayerhq.hu/
COMMENT=	DVD access library
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	misc/dvdread.pc.in

MESSAGE_SUBST+=		PKGBASE=${PKGBASE}

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
