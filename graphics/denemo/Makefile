# $NetBSD: Makefile,v 1.2 2000/11/11 17:49:26 tron Exp $
#

DISTNAME=	denemo-0.5.4
CATEGORIES=	graphics print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=denemo/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://denemo.sourceforge.net/

DEPENDS+=	lilypond-*:../../print/lilypond
DEPENDS+=	gtk+>=1.2.0:../../x11/gtk

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

.include "../../mk/bsd.pkg.mk"
