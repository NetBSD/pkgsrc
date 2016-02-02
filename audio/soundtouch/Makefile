# $NetBSD: Makefile,v 1.3 2016/02/02 06:15:02 dbj Exp $

DISTNAME=	soundtouch-1.9.0
CATEGORIES=	audio
MASTER_SITES=	http://www.surina.net/soundtouch/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.surina.net/soundtouch/
COMMENT=	Library for changing the tempo, pitch, and playback rates of audio
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	libtool-base-[0-9]*:../../devel/libtool-base

WRKSRC=		${WRKDIR}/soundtouch
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config autoconf automake autoreconf
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	soundtouch-1.4.pc.in
PKGCONFIG_OVERRIDE+=	soundtouch.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../mk/bsd.pkg.mk"
