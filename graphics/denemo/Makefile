# $NetBSD: Makefile,v 1.13 2005/04/11 21:46:01 tv Exp $
#

DISTNAME=	denemo-0.5.4
PKGREVISION=	6
CATEGORIES=	graphics print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=denemo/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://denemo.sourceforge.net/
COMMENT=	GUI musical score editor written in C/GTK+

DEPENDS+=	lilypond-[0-9]*:../../print/lilypond

GNU_CONFIGURE=	YES

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
