# $NetBSD: Makefile,v 1.7 2003/05/03 22:44:54 wiz Exp $
#

DISTNAME=	denemo-0.5.4
PKGREVISION=	3
CATEGORIES=	graphics print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=denemo/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://denemo.sourceforge.net/
COMMENT=	GUI musical score editor written in C/GTK+

DEPENDS+=	lilypond-[0-9]*:../../print/lilypond

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
