# $NetBSD: Makefile,v 1.2 2003/06/18 18:09:56 salo Exp $
#

DISTNAME=	wideangleFeb02
PKGNAME=	gimp-wideangle-20010202
WRKSRC=		${WRKDIR}/wideangle
CATEGORIES=	graphics
MASTER_SITES=	http://www.ozemail.com.au/~hodsond/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.ozemail.com.au/~hodsond/
COMMENT=	GIMP plugin for wideangle lens distortions

USE_BUILDLINK2=	YES
USE_GMAKE=	YES

ALL_TARGET=	wideangle

.include "../../graphics/gimp-base/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
