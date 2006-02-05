# $NetBSD: Makefile,v 1.8 2006/02/05 23:09:31 joerg Exp $
#

DISTNAME=	wideangleFeb03
PKGNAME=	gimp-wideangle-0.4
PKGREVISION=			4
CATEGORIES=	graphics
MASTER_SITES=	http://www.ozemail.com.au/~hodsond/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ozemail.com.au/~hodsond/
COMMENT=	GIMP plugin for wideangle lens distortions

WRKSRC=		${WRKDIR}/wideangle
USE_TOOLS+=	gmake

BUILD_TARGET=	wideangle

.include "../../graphics/gimp1-base/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
