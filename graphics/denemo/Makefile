# $NetBSD: Makefile,v 1.16 2006/01/24 07:32:10 wiz Exp $
#

DISTNAME=	denemo-0.5.4
PKGREVISION=	7
CATEGORIES=	graphics print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=denemo/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://denemo.sourceforge.net/
COMMENT=	GUI musical score editor written in C/GTK+

BROKEN_IN=	pkgsrc-2005Q4

DEPENDS+=	lilypond-[0-9]*:../../print/lilypond

GNU_CONFIGURE=	YES

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
