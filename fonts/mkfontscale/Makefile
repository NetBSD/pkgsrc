# $NetBSD: Makefile,v 1.12 2004/01/20 12:15:17 agc Exp $
#

DISTNAME=	mkfontscale-20020524
PKGREVISION=	2
CATEGORIES=	fonts
MASTER_SITES=	http://www.pps.jussieu.fr/~jch/software/files/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.pps.jussieu.fr/~jch/software/files/
COMMENT=	Create an index of scalable font files for X

WRKSRC=		${WRKDIR}/mkfontscale
USE_BUILDLINK2=	YES
USE_IMAKE=	YES

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/include/X11/fonts/fontenc.h)
PKG_FAIL_REASON= "Needs the fontenc.h header file, which comes with newer XFree versions."
.endif

.include "../../mk/bsd.pkg.mk"
