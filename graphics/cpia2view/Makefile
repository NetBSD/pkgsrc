# $NetBSD: Makefile,v 1.1.1.1 2004/03/07 08:15:20 hamajima Exp $
#

DISTNAME=	cpia2_driver-1.0
PKGNAME=	cpia2view-0.03
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cpia2/}
EXTRACT_SUFX=	.tgz

PATCH_SITES=	http://www2.starcat.ne.jp/~takam/bsd/
PATCHFILES= 	cpia2_driver-1.0-bsd-0.03.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www2.starcat.ne.jp/~takam/bsd/NetBSD.html#cpia2
COMMENT=	USB cameras based CPiA2 Utility Programs

USE_BUILDLINK3=		# defined

do-build:
	for f in cpia2shot cpia2view ; do		\
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}	\
		NOGCCERROR=				\
		${MAKE_PROGRAM} -f ${MAKEFILE}.$$f ;	\
	done

do-install:
	for f in cpia2shot cpia2view ; do			\
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}		\
		${MAKE_PROGRAM} -f ${MAKEFILE}.$$f install ;	\
	done

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
