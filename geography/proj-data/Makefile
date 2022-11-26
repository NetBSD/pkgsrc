# $NetBSD: Makefile,v 1.1 2022/11/26 15:08:20 gdt Exp $

DISTNAME=	proj-data-1.4
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=OSGeo/}
GITHUB_PROJECT=	PROJ-data
GITHUB_RELEASE=	1.4.0

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://proj.org/
COMMENT=	Cartographic projection software data files
# There are a large number of licenses for individual data files, but
# the project requires that they all be Open Source.  Updated from
# https://github.com/OSGeo/PROJ-data/blob/master/copyright_and_licenses.csv
# in 2022-11.
LICENSE=	public-domain \
		AND cc-by-v4.0 \
		AND cc-by-sa-v4.0 \
		AND cc0-1.0-universal \
		AND 2-clause-bsd \
#		AND "Open License France - https://www.etalab.gouv.fr/wp-content/uploads/2014/05/Open_Licence.pdf" \
#		AND OGL-Canada-2.0 \
#		AND "Data licence Germany - attribution - version 2.0"

# The distfile simply unpacks a large number of data files.  There is no concept of build.
WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
NO_BUILD=	yes

PROJ_DATA=		${PREFIX}/share/proj

INSTALLATION_DIRS+=	${PROJ_DATA}

do-install:
	${INSTALL_DATA} ${WRKSRC}/* ${DESTDIR}/${PROJ_DATA}

.include "../../mk/bsd.pkg.mk"
