# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 17:45:41 rh Exp $
#

DISTNAME=	denemo-0.5.4
CATEGORIES=	graphics print
MASTER_SITES=	http://download.sourceforge.net/denemo/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://denemo.sourceforge.net/

DEPENDS+=	lilypond-*:../../print/lilypond
DEPENDS+=	gtk+>=1.2.0:../../x11/gtk

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

.include "../../mk/bsd.pkg.mk"
