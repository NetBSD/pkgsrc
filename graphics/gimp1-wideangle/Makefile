# $NetBSD: Makefile,v 1.9 2006/03/04 21:29:48 jlam Exp $
#

DISTNAME=	wideangleFeb03
PKGNAME=	gimp-wideangle-0.4
PKGREVISION=			4
CATEGORIES=	graphics
MASTER_SITES=	http://www.ozemail.com.au/~hodsond/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ozemail.com.au/~hodsond/
COMMENT=	GIMP plugin for wideangle lens distortions

WRKSRC=		${WRKDIR}/wideangle
USE_TOOLS+=	gmake

BUILD_TARGET=	wideangle

.include "../../graphics/gimp1-base/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
