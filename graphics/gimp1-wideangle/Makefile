# $NetBSD: Makefile,v 1.6 2005/04/11 21:46:03 tv Exp $
#

DISTNAME=	wideangleFeb03
PKGNAME=	gimp-wideangle-0.4
PKGREVISION=			3
CATEGORIES=	graphics
MASTER_SITES=	http://www.ozemail.com.au/~hodsond/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ozemail.com.au/~hodsond/
COMMENT=	GIMP plugin for wideangle lens distortions

WRKSRC=		${WRKDIR}/wideangle
USE_GNU_TOOLS+=	make

BUILD_TARGET=	wideangle

.include "../../graphics/gimp1-base/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
