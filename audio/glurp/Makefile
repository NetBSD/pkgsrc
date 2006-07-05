# $NetBSD: Makefile,v 1.8 2006/07/05 05:37:39 jlam Exp $
#

DISTNAME=	glurp-0.11.6
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=glurp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.musicpd.org/glurp.shtml
COMMENT=	Graphical GTK+2-based client for musicpd

GNU_CONFIGURE=	yes
USE_DIRS+=	xdg-1.1
USE_TOOLS+=	intltool pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
