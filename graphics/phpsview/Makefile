# $NetBSD: Makefile,v 1.14 2006/09/09 02:42:01 obache Exp $
#

DISTNAME=	pwc-9.0.2
PKGNAME=	phpsview-${DISTNAME:C/.*-//}
PKGREVISION=	2
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.smcc.demon.nl/webcam/

PATCH_SITES=	http://www.medias.ne.jp/~takam/bsd/
PATCHFILES= 	pwc-9.0.2-bsd-0.03.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www.medias.ne.jp/~takam/bsd/NetBSD.html#qcamPro
COMMENT=	Philips USB Cameras Utilities

INSTALLATION_DIRS=	bin

do-build:
	for f in phpsshot phpsview ; do				\
		cd ${WRKSRC}/2.4 && ${SETENV} ${MAKE_ENV}	\
		NOGCCERROR=					\
		${MAKE_PROGRAM} -f ${MAKE_FILE}.$$f ;		\
	done

do-install:
	for f in phpsshot phpsview ; do				\
		cd ${WRKSRC}/2.4 &&				\
		${INSTALL_PROGRAM} $$f ${PREFIX}/bin ;	\
	done

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
