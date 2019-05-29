# $NetBSD: Makefile,v 1.4 2019/05/29 21:28:03 adam Exp $

DISTNAME=	soundtouch-2.1.2
CATEGORIES=	audio
MASTER_SITES=	https://gitlab.com/soundtouch/soundtouch/-/archive/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.surina.net/soundtouch/
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
