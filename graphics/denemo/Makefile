# $NetBSD: Makefile,v 1.17 2006/02/05 23:09:29 joerg Exp $
#

DISTNAME=	denemo-0.5.4
PKGREVISION=	8
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
