# $NetBSD: Makefile,v 1.4 2001/09/27 23:18:09 jlam Exp $
#

DISTNAME=	denemo-0.5.4
CATEGORIES=	graphics print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=denemo/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://denemo.sourceforge.net/
COMMENT=	GUI musical score editor written in C/gtk+

DEPENDS+=	lilypond-[0-9]*:../../print/lilypond
DEPENDS+=	gtk+>=1.2.0:../../x11/gtk

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

.include "../../mk/bsd.pkg.mk"
