# $NetBSD: Makefile,v 1.6 2021/11/13 10:56:22 nia Exp $

DISTNAME=	soundtouch-2.3.1
CATEGORIES=	audio
MASTER_SITES=	https://www.surina.net/soundtouch/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.surina.net/soundtouch/
COMMENT=	Library for changing the tempo, pitch, and playback rates of audio
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake autoreconf pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	soundtouch.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -f -i

.include "../../mk/bsd.pkg.mk"
