# $NetBSD: Makefile,v 1.5 2003/07/17 21:40:55 grant Exp $
#

DISTNAME=	wideangleFeb03
PKGNAME=	gimp-wideangle-0.4
PKGREVISION=			1
WRKSRC=		${WRKDIR}/wideangle
CATEGORIES=	graphics
MASTER_SITES=	http://www.ozemail.com.au/~hodsond/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ozemail.com.au/~hodsond/
COMMENT=	GIMP plugin for wideangle lens distortions

USE_BUILDLINK2=	YES
USE_GMAKE=	YES

ALL_TARGET=	wideangle

.include "../../graphics/gimp-base/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
