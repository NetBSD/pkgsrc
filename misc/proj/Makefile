# $NetBSD: Makefile,v 1.5 2002/05/03 22:20:06 jtb Exp $

DISTNAME=		proj-4.4.5
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.remotesensing.org/pub/proj/
DISTFILES=		proj-4.4.5.tar.gz proj-pdf-docs.tar.gz \
			proj-nad27-1.1.tar.gz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.remotesensing.org/proj/
COMMENT=		Cartographic projection software

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

NAD27_FILES=FL.lla MD.lla README.NADUS TN.lla WI.lla WO.lla alaska.lla	\
	conus.lla hawaii.lla ntv1_can.dat prvi.lla stgeorge.lla		\
	stlrnc.lla stpaul.lla

post-extract:
	cd ${WRKDIR} &&	${LN} ${NAD27_FILES} ${WRKDIR}/${DISTNAME}/nad
 
post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/proj
	${INSTALL_DATA} ${WRKDIR}/*.pdf ${PREFIX}/share/doc/proj/

.include "../../mk/bsd.pkg.mk"
