# $NetBSD: Makefile,v 1.1.1.1 2003/06/18 10:34:28 drochner Exp $
#

DISTNAME=		wideangleFeb02
PKGNAME=		gimp-wideangle-Feb02
CATEGORIES=		graphics
MASTER_SITES=		http://www.ozemail.com.au/~hodsond/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.ozemail.com.au/~hodsond/
COMMENT=		GIMP plugin for wideangle lens distortions

WRKSRC=		${WRKDIR}/wideangle
USE_BUILDLINK2=		yes
ALL_TARGET=	wideangle
USE_GMAKE=	yes

.include "../../graphics/gimp-base/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
