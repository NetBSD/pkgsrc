# $NetBSD: Makefile,v 1.7 2016/08/30 10:57:35 plunky Exp $
#

# The package version is the latest date of the distfiles.
#
PKGNAME=	qcad-partlibrary-20160819
CATEGORIES=	cad
MASTER_SITES=	http://www.qcad.org/archives/partlibrary/
DIST_SUBDIR=	qcad-partlibrary
DISTFILES=	Architecture-2012-07-09.zip \
		Chemistry-2016-08-19.zip \
		Electronics-2012-07-09.zip \
		GIS-2012-07-09.zip \
		Hydraulics-2012-07-09.zip \
		LRMCircuits-2014-02-05.zip \
		Mechanics-2012-07-09.zip \
		Misc-2016-08-08.zip \
		MSR-2016-08-19.zip \
		Processing-2016-08-19.zip \
		thenounproject.com-2012-07-09.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qcad.org/en/qcad-add-ons
COMMENT=	Parts libraries for the QCad 2D CAD system
LICENSE=	gnu-gpl-v3

DEPENDS+=	qcad>=3.15.4.1:../../cad/qcad

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_TOOLS+=	chmod find pax
AUTO_MKDIRS=	yes

EXTRACT_DIR=	${WRKSRC}

post-extract:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} u=rw,go=r "{}" "+"

do-install:
	cd ${WRKSRC} && ${PAX} -rwpm . ${DESTDIR}${PREFIX}/share/qcad/libraries

.include "../../mk/bsd.pkg.mk"
