# $NetBSD: Makefile,v 1.1 2014/08/26 10:44:15 wiz Exp $

DISTNAME=	libopenmpt-0.2.4115-beta5
PKGNAME=	${DISTNAME:S/-beta/beta/}
CATEGORIES=	audio
MASTER_SITES=	http://lib.openmpt.org/files/libopenmpt/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lib.openmpt.org/libopenmpt/
COMMENT=	Library to decode tracked music files into a raw PCM audio stream
LICENSE=	modified-bsd

BUILD_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

WRKSRC=		${WRKDIR}/${DISTNAME:C/-beta.*//}
USE_LANGUAGES=	c c++
USE_TOOLS=	gmake pkg-config

# installation uses non-portable 'install -D'
# http://bugs.openmpt.org/view.php?id=581
MAKE_FLAGS+=	INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}
MAKE_FLAGS+=	INSTALL_DATA=${INSTALL_DATA:Q}
MAKE_FLAGS+=	PKGMANDIR=${PKGMANDIR:Q}
INSTALLATION_DIRS=	bin include/libopenmpt lib/pkgconfig ${PKGMANDIR}/man1 share/doc/libopenmpt/examples

.include "options.mk"

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
