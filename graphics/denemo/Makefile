# $NetBSD: Makefile,v 1.3 2001/02/16 15:22:16 wiz Exp $
#

DISTNAME=	denemo-0.5.4
CATEGORIES=	graphics print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=denemo/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://denemo.sourceforge.net/
COMMENT=	GUI musical score editor written in C/gtk+

DEPENDS+=	lilypond-*:../../print/lilypond
DEPENDS+=	gtk+>=1.2.0:../../x11/gtk

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

.include "../../mk/bsd.pkg.mk"
