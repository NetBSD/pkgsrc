# $NetBSD: Makefile,v 1.5 2004/10/03 00:14:57 tv Exp $
#

DISTNAME=	qce-ga-0.40d
PKGNAME=	qcamview-0.4
PKGREVISION=	1
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qce-ga/}

PATCH_SITES=	http://www2.starcat.ne.jp/~takam/bsd/
PATCHFILES= 	qce-ga-bsd-0.04.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www2.starcat.ne.jp/~takam/bsd/NetBSD.html#qcam
COMMENT=	Logitech Quickcam Express USB Utilities

USE_BUILDLINK3=		yes

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

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
