# $NetBSD: Makefile,v 1.12 2009/08/26 19:57:09 sno Exp $
#

DISTNAME=	glurp-0.11.6
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=glurp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.musicpd.org/glurp.shtml
COMMENT=	Graphical GTK+2-based client for musicpd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
