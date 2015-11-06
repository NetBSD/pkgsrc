# $NetBSD: Makefile,v 1.9 2015/11/06 11:33:39 wiz Exp $

DISTNAME=	libopenmpt-0.2.5705-beta15-autotools
PKGNAME=	${DISTNAME:C/-beta.*//}
CATEGORIES=	audio
MASTER_SITES=	http://lib.openmpt.org/files/libopenmpt/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lib.openmpt.org/libopenmpt/
COMMENT=	Library to decode tracked music files into a raw PCM audio stream
LICENSE=	modified-bsd

BUILD_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

WRKSRC=		${WRKDIR}/${DISTNAME:C/-beta.*-/-/}
USE_LANGUAGES=	c c++
USE_TOOLS=	gmake pkg-config

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
PKGCONFIG_OVERRIDE=		libmodplug/libmodplug.pc.in libopenmpt/libopenmpt.pc.in

.include "options.mk"

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
