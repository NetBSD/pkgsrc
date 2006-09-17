# $NetBSD: Makefile,v 1.2 2006/09/17 14:48:18 joerg Exp $
#

DISTNAME=	icon-naming-utils-0.8.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://tango-project.org/releases/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://tango.freedesktop.org/
COMMENT=	Adapts GNOME and KDE icon names to the Icon Naming Specification

DEPENDS+=	p5-XML-Simple>=2.14:../../textproc/p5-XML-Simple

GNU_CONFIGURE=	yes
USE_DIRS+=	xdg-1.4
USE_LANGUAGES=	# none, not even C
USE_TOOLS+=	gmake intltool perl:run

.include "../../mk/bsd.pkg.mk"
