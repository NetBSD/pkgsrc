# $NetBSD: Makefile,v 1.21 2009/07/22 09:01:30 wiz Exp $
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
USE_TOOLS+=	pkg-config

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
