# $NetBSD: Makefile,v 1.1.1.1 2005/01/23 02:35:11 hamajima Exp $
#

DISTNAME=	ov51x-1.65-1.11-mark
PKGNAME=	ov519view-0.00
CATEGORIES=	graphics x11
MASTER_SITES=	http://alpha.dyndns.org/ov511/download/ov51x/
EXTRACT_SUFX=	.tar.bz2

PATCH_SITES=	http://www2.starcat.ne.jp/~takam/bsd/
PATCHFILES=	ov51x-1.65-1.11-mark-bsd-0.00.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www2.starcat.ne.jp/~takam/bsd/NetBSD.html#ov519
COMMENT=	USB cameras based OV519 Utility Programs

USE_BUILDLINK3=		yes

do-build:
	for f in ov519shot ov519view ; do               \
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}   \
		NOGCCERROR=                             \
		${MAKE_PROGRAM} -f ${MAKEFILE}.$$f ;    \
	done

do-install:
	for f in ov519shot ov519view ; do                       \
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}           \
		${MAKE_PROGRAM} -f ${MAKEFILE}.$$f install ;    \
	done

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
