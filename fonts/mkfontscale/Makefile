# $NetBSD: Makefile,v 1.9 2003/07/21 16:47:08 martti Exp $

DISTNAME=	mkfontscale-20020524
PKGREVISION=	1
WRKSRC=		${WRKDIR}/mkfontscale
CATEGORIES=	fonts
MASTER_SITES=	http://www.pps.jussieu.fr/~jch/software/files/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.pps.jussieu.fr/~jch/software/files/
COMMENT=	Create an index of scalable font files for X

USE_IMAKE=	YES

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/include/X11/fonts/fontenc.h)
PKG_FAIL_REASON= "Needs the fontenc.h header file, which comes with newer XFree versions."
.endif

.include "../../mk/bsd.pkg.mk"
