# $NetBSD: Makefile,v 1.29 2014/02/12 23:18:41 tron Exp $
#

DISTNAME=	FlightCrew-0.7.2-Code
PKGNAME=	${DISTNAME:S/-Code//}
PKGREVISION=	22
CATEGORIES=	textproc
MASTER_SITES=	http://flightcrew.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/flightcrew/
COMMENT=	EPUB validator
LICENSE=	gnu-lgpl-v3 AND cc-by-sa-v3.0

WRKSRC=		${WRKDIR}

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

SUBST_CLASSES+=		d2u
SUBST_STAGE.d2u=	post-extract
SUBST_MESSAGE.d2u=	Removing CR end-of-line markers.
SUBST_FILES.d2u=	CMakeLists.txt
SUBST_FILES.d2u+=	src/FlightCrew/tests/CMakeLists.txt
SUBST_FILES.d2u+=	src/FlightCrew/Validators/Opf/ReachabilityAnalysis.cpp
SUBST_FILTER_CMD.d2u=	${TR} -d '\r'

.include "../../mk/compiler.mk"
# GCC 4.4 and above needs this
.if !empty(PKGSRC_COMPILER:Mgcc) && !empty(CC_VERSION:Mgcc-4.[4-9]*)
_WRAP_EXTRA_ARGS.CXX+=	-std=c++0x
.elif !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CXX+=	-std=c++11
.endif

.include "../../devel/googletest/buildlink3.mk"
.include "../../devel/gmock/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
