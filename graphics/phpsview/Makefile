# $NetBSD: Makefile,v 1.3 2004/01/03 18:49:44 reed Exp $
#

DISTNAME=	pwc-8.12
PKGNAME=	phpsview-1.02
PKGREVISION=	1
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.smcc.demon.nl/webcam/

PATCH_SITES=	http://www2.starcat.ne.jp/~takam/bsd/
PATCHFILES= 	pwc-8.12-bsd-0.02.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www2.starcat.ne.jp/~takam/bsd/NetBSD.html#qcamPro
COMMENT=	Philips USB Cameras Utilities

USE_BUILDLINK2=		# defined

do-build:
	for f in phpsshot phpsview ; do				\
		cd ${WRKSRC}/2.4.22 && ${SETENV} ${MAKE_ENV}	\
		${MAKE_PROGRAM} -f ${MAKEFILE}.$$f ;		\
	done

do-install:
	for f in phpsshot phpsview ; do				\
		cd ${WRKSRC}/2.4.22 &&				\
		${INSTALL_PROGRAM} $$f ${PREFIX}/bin ;	\
	done

.include "../../graphics/imlib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
