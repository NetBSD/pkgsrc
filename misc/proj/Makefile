# $NetBSD: Makefile,v 1.13 2004/10/03 00:13:00 tv Exp $

DISTNAME=		proj-4.4.7
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.remotesensing.org/pub/proj/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} proj-nad27-1.1.tar.gz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.remotesensing.org/proj/
COMMENT=		Cartographic projection software

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes

NAD27_FILES=FL.lla MD.lla README.NADUS TN.lla WI.lla WO.lla alaska.lla	\
	conus.lla hawaii.lla ntv1_can.dat prvi.lla stgeorge.lla		\
	stlrnc.lla stpaul.lla

post-extract:
	cd ${WRKDIR} &&	${LN} ${NAD27_FILES} ${WRKDIR}/${DISTNAME}/nad

.include "../../mk/bsd.pkg.mk"
