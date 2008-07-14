# $NetBSD: Makefile,v 1.20 2008/07/14 12:56:05 joerg Exp $
#

DISTNAME=	denemo-0.7.6
CATEGORIES=	graphics print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=denemo/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://denemo.sourceforge.net/
COMMENT=	GUI musical score editor written in C/GTK+

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	lilypond-[0-9]*:../../print/lilypond

BROKEN_IN=		pkgsrc-2006Q4

GNU_CONFIGURE=	YES
USE_DIRS+=	xdg-1.4
USE_TOOLS+=	pkg-config

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
