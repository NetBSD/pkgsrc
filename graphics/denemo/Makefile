# $NetBSD: Makefile,v 1.6 2003/05/02 11:55:12 wiz Exp $
#

DISTNAME=	denemo-0.5.4
PKGREVISION=	2
CATEGORIES=	graphics print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=denemo/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://denemo.sourceforge.net/
COMMENT=	GUI musical score editor written in C/GTK+

DEPENDS+=	lilypond-[0-9]*:../../print/lilypond
DEPENDS+=	gtk+>=1.2.10nb4:../../x11/gtk

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

.include "../../mk/bsd.pkg.mk"
