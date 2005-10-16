# $NetBSD: Makefile,v 1.8 2005/10/16 12:47:24 jdolecek Exp $
#

DISTNAME=	pwc-9.0.2
PKGNAME=	phpsview-${DISTNAME:C/.*-//}
PKGREVISION=	# empty
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.smcc.demon.nl/webcam/

PATCH_SITES=	http://www2.starcat.ne.jp/~takam/bsd/
PATCHFILES= 	pwc-9.0.2-bsd-0.03.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www2.starcat.ne.jp/~takam/bsd/NetBSD.html#qcamPro
COMMENT=	Philips USB Cameras Utilities

INSTALLATION_DIRS=	bin

do-build:
	for f in phpsshot phpsview ; do				\
		cd ${WRKSRC}/2.4 && ${SETENV} ${MAKE_ENV}	\
		${MAKE_PROGRAM} -f ${MAKEFILE}.$$f ;		\
	done

do-install:
	for f in phpsshot phpsview ; do				\
		cd ${WRKSRC}/2.4 &&				\
		${INSTALL_PROGRAM} $$f ${PREFIX}/bin ;	\
	done

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
