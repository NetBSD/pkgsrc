# $NetBSD: Makefile,v 1.6.4.1 2008/07/20 11:06:46 rtr Exp $
#

DISTNAME=	icon-naming-utils-0.8.6
CATEGORIES=	graphics
MASTER_SITES=	http://tango.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tango.freedesktop.org/
COMMENT=	Adapts GNOME and KDE icon names to the Icon Naming Specification

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-XML-Simple>=2.14:../../textproc/p5-XML-Simple

GNU_CONFIGURE=	yes
USE_DIRS+=	xdg-1.4
USE_LANGUAGES=	# none, not even C
USE_TOOLS+=	gmake intltool perl:run

.include "../../mk/bsd.pkg.mk"
