# $NetBSD: Makefile,v 1.1.1.1 2011/07/29 19:32:18 ryoon Exp $
#

DISTNAME=	FlightCrew-0.7.1-Code
PKGNAME=	${DISTNAME:S/-Code//}
CATEGORIES=	textproc
MASTER_SITES=	http://flightcrew.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/flightcrew/
COMMENT=	EPUB validator
LICENSE=	gnu-lgpl-v3 AND cc-by-sa-v3.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

BUILDLINK_TRANSFORM+=	l:BoostParts:boost_date_time:boost_filesystem:boost_regex:boost_system:boost_thread:boost_program_options
BUILDLINK_TRANSFORM+=	l:Xerces:xerces-c
BUILDLINK_TRANSFORM+=	l:zlib:z

SUBST_CLASSES+=			fix-damaged
SUBST_STAGE.fix-damaged=	pre-patch
SUBST_MESSAGE.fix-damaged=	fixing
SUBST_FILES.fix-damaged=	src/FlightCrew/tests/misc_tests/ConvertUtf8PathToBoostPath_test.cpp
SUBST_SED.fix-damaged+=		-e "2,2s/^/\//" # commented-out
SUBST_SED.fix-damaged+=		-e "1,1d" # deleted

.include "../../devel/googletest/buildlink3.mk"
.include "../../devel/gmock/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
