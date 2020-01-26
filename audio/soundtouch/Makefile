# $NetBSD: Makefile,v 1.5 2020/01/26 17:30:45 rillig Exp $

DISTNAME=	soundtouch-2.1.2
CATEGORIES=	audio
MASTER_SITES=	https://gitlab.com/soundtouch/soundtouch/-/archive/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

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
