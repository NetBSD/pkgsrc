# $NetBSD: Makefile,v 1.1.1.1 2005/10/15 01:00:05 xtraeme Exp $
#

DISTNAME=	glurp-0.11.6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=glurp/}

MAINTAINER=	lems@gmx.net
HOMEPAGE=	http://www.musicpd.org/glurp.shtml
COMMENT=	Graphical GTK+2 based client for musicpd

GNU_CONFIGURE=	yes
USE_DIRS+=	xdg-1.1
USE_TOOLS+=	pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
