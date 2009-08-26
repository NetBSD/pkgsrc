# $NetBSD: Makefile,v 1.13 2009/08/26 19:57:42 sno Exp $
#

DISTNAME=	wideangleFeb03
PKGNAME=	gimp-wideangle-0.4
PKGREVISION=			6
CATEGORIES=	graphics
MASTER_SITES=	http://members.ozemail.com.au/~hodsond/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://members.ozemail.com.au/~hodsond/
COMMENT=	GIMP plugin for wideangle lens distortions

WRKSRC=		${WRKDIR}/wideangle
USE_TOOLS+=	gmake pkg-config

BUILD_TARGET=	wideangle

.include "../../graphics/gimp1-base/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
