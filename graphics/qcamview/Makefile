# $NetBSD: Makefile,v 1.2 2004/01/03 18:49:44 reed Exp $
#

DISTNAME=	qce-ga-0.40d
PKGNAME=	qcamview-0.2
PKGREVISION=	1
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qce-ga/}

PATCH_SITES=	http://www2.starcat.ne.jp/~takam/bsd/
PATCHFILES= 	qce-ga-bsd-0.02.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www2.starcat.ne.jp/~takam/bsd/NetBSD.html#qcam
COMMENT=	Logitech Quickcam Express USB Utilities

USE_BUILDLINK2=		# defined

do-build:
	for f in qcamshot qcamview ; do				\
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}		\
		${MAKE_PROGRAM} -f ${MAKEFILE}.$$f ;		\
	done

do-install:
	for f in qcamshot qcamview ; do				\
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}		\
		${MAKE_PROGRAM} -f ${MAKEFILE}.$$f install ;	\
	done

.include "../../graphics/imlib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
