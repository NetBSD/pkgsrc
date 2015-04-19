# $NetBSD: Makefile,v 1.5 2015/04/19 18:20:49 wiz Exp $

DISTNAME=	libopenmpt-0.2.4954-beta12-autotools
PKGNAME=	${DISTNAME:S/-beta/beta/:S/-autotools//}
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
#MAKE_FLAGS+=			MANDIR=${PREFIX}/${PKGMANDIR}
#MAKE_FLAGS+=			INSTALL_LIB=${INSTALL_LIB:Q}
PKGCONFIG_OVERRIDE=		bin/libopenmpt.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "options.mk"

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
