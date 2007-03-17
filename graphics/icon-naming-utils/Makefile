# $NetBSD: Makefile,v 1.4 2007/03/17 16:48:49 wiz Exp $
#

DISTNAME=	icon-naming-utils-0.8.2
CATEGORIES=	graphics
MASTER_SITES=	http://tango-project.org/releases/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://tango.freedesktop.org/
COMMENT=	Adapts GNOME and KDE icon names to the Icon Naming Specification

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-XML-Simple>=2.14:../../textproc/p5-XML-Simple

GNU_CONFIGURE=	yes
USE_DIRS+=	xdg-1.4
USE_LANGUAGES=	# none, not even C
USE_TOOLS+=	gmake intltool perl:run

.include "../../mk/bsd.pkg.mk"
