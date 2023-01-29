# $NetBSD: Makefile,v 1.66 2023/01/29 21:17:53 ryoon Exp $

DISTNAME=	FlightCrew-0.7.2-Code
PKGNAME=	${DISTNAME:S/-Code//}
PKGREVISION=	51
CATEGORIES=	textproc
MASTER_SITES=	http://flightcrew.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/Sigil-Ebook/flightcrew
COMMENT=	EPUB validator
LICENSE=	gnu-lgpl-v3 AND cc-by-sa-v3.0

WRKSRC=		${WRKDIR}

USE_LANGUAGES=	c c++11
USE_CMAKE=	yes

# Work around NetBSD unzip vs others for patched files.
SUBST_CLASSES+=		cr
SUBST_STAGE.cr=		post-extract
SUBST_FILES.cr+=	CMakeLists.txt src/FlightCrew/CMakeLists.txt
SUBST_FILES.cr+=	src/FlightCrew/Validators/Opf/ReachabilityAnalysis.cpp
SUBST_FILES.cr+=	src/FlightCrew/tests/CMakeLists.txt
SUBST_FILES.cr+=	src/XercesExtensions/LocationAwareDOMParser.cpp
SUBST_FILES.cr+=	src/utf8-cpp/utf8/core.h
SUBST_FILTER_CMD.cr=	${TR} -d '\r'
SUBST_NOOP_OK.cr=	yes

BUILDLINK_TRANSFORM+=	l:BoostParts:boost_date_time:boost_filesystem:boost_regex:boost_system:boost_thread:boost_program_options
BUILDLINK_TRANSFORM+=	l:Xerces:xerces-c
BUILDLINK_TRANSFORM+=	l:zlib:z

SUBST_CLASSES+=			fix-damaged
SUBST_STAGE.fix-damaged=	pre-patch
SUBST_MESSAGE.fix-damaged=	fixing
SUBST_FILES.fix-damaged=	src/FlightCrew/tests/misc_tests/ConvertUtf8PathToBoostPath_test.cpp
SUBST_SED.fix-damaged+=		-e "2,2s/^/\//" # commented-out
SUBST_SED.fix-damaged+=		-e "1,1d" # deleted

post-extract:
	${RM} -rf ${WRKDIR}/src/BoostParts ${WRKDIR}/src/Xerces ${WRKDIR}/src/zlib ${WRKDIR}/src/googlemock

.include "../../devel/googletest/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
