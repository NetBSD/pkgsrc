# $NetBSD: Makefile,v 1.14 2004/06/15 02:33:26 minskim Exp $
#

DISTNAME=	mkfontscale-20020524
PKGREVISION=	3
CATEGORIES=	fonts
MASTER_SITES=	http://www.pps.jussieu.fr/~jch/software/files/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.pps.jussieu.fr/~jch/software/files/
COMMENT=	Create an index of scalable font files for X

WRKSRC=		${WRKDIR}/mkfontscale
USE_BUILDLINK3=	YES
USE_IMAKE=	YES

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/include/X11/fonts/fontenc.h)
PKG_FAIL_REASON= "Needs the fontenc.h header file, which comes with newer XFree versions."
.endif

.if exists(${X11BASE}/bin/mkfontscale)
CONFLICTS+=	xpkgwedge>=1.11
.endif

.include "../../mk/bsd.pkg.mk"
