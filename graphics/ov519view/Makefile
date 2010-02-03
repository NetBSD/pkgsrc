# $NetBSD: Makefile,v 1.14 2010/02/03 22:32:00 joerg Exp $
#

DISTNAME=	ov51x-1.65-1.11-mark
PKGNAME=	ov519view-0.00
PKGREVISION=	6
CATEGORIES=	graphics x11
MASTER_SITES=	http://alpha.dyndns.org/ov511/download/ov51x/
EXTRACT_SUFX=	.tar.bz2

PATCH_SITES=	http://home.384.jp/takam/bsd/
PATCHFILES=	ov51x-1.65-1.11-mark-bsd-0.00.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://home.384.jp/takam/bsd/NetBSD.html#ov519
COMMENT=	USB cameras based OV519 Utility Programs

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

MAKE_ENV+=	${BSD_MAKE_ENV}

do-build:
	for f in ov519shot ov519view ; do               \
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}   \
		NOGCCERROR=                             \
		${MAKE_PROGRAM} -f ${MAKE_FILE}.$$f ;    \
	done

do-install:
	for f in ov519shot ov519view ; do                       \
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}           \
		${MAKE_PROGRAM} -f ${MAKE_FILE}.$$f install ${INSTALL_MAKE_FLAGS};    \
	done

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
