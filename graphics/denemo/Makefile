# $NetBSD: Makefile,v 1.24 2010/06/13 22:44:28 wiz Exp $
#

DISTNAME=	denemo-0.7.6
PKGREVISION=	2
CATEGORIES=	graphics print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=denemo/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://denemo.sourceforge.net/
COMMENT=	GUI musical score editor written in C/GTK+

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	lilypond-[0-9]*:../../print/lilypond

GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
