# $NetBSD: Makefile,v 1.7 2004/01/20 12:18:16 agc Exp $
#

DISTNAME=	wideangleFeb03
PKGNAME=	gimp-wideangle-0.4
PKGREVISION=			2
CATEGORIES=	graphics
MASTER_SITES=	http://www.ozemail.com.au/~hodsond/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ozemail.com.au/~hodsond/
COMMENT=	GIMP plugin for wideangle lens distortions

WRKSRC=		${WRKDIR}/wideangle
USE_BUILDLINK2=	YES
USE_GMAKE=	YES

ALL_TARGET=	wideangle

.include "../../graphics/gimp-base/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
