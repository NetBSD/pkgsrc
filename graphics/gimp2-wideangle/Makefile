# $NetBSD: Makefile,v 1.4 2005/11/25 21:23:15 wiz Exp $
#

DISTNAME=	wideangle
PKGNAME=	gimp2-wideangle-1.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.ozemail.com.au/~hodsond/
EXTRACT_SUFX=	.c

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ozemail.com.au/~hodsond/wideangle.html
COMMENT=	GIMP plugin for wideangle lens distortions

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=         ${WRKDIR}
EXTRACT_CMD=    ${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}

do-build:
	(cd ${WRKSRC} && gimptool-2.0 --build wideangle.c)

do-install:
	(cd ${WRKSRC} && gimptool-2.0 --install-admin-bin wideangle)

.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
