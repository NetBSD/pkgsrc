# $NetBSD: Makefile,v 1.6 2003/02/26 04:01:10 jschauma Exp $

DISTNAME=	mkfontscale-20020524
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://www.pps.jussieu.fr/~jch/software/files/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://www.pps.jussieu.fr/~jch/software/files/
COMMENT=	create an index of scalable font files for X

USE_IMAKE=	YES

WRKSRC=		${WRKDIR}/mkfontscale

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/include/X11/fonts/fontenc.h)
PKG_FAIL_REASON= "Needs the fontenc.h header file, which comes with newer XFree versions."
.endif

.include "../../mk/bsd.pkg.mk"
