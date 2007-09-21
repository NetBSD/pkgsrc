# $NetBSD: Makefile,v 1.9 2007/09/21 13:03:26 wiz Exp $
#

DISTNAME=	glurp-0.11.6
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=glurp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.musicpd.org/glurp.shtml
COMMENT=	Graphical GTK+2-based client for musicpd

GNU_CONFIGURE=	yes
USE_DIRS+=	xdg-1.1
USE_TOOLS+=	intltool pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
