# $NetBSD: Makefile,v 1.21 2021/05/24 19:52:22 wiz Exp $
#

DISTNAME=	icon-naming-utils-0.8.90
PKGREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	http://tango.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tango.freedesktop.org/
COMMENT=	Adapts GNOME and KDE icon names to the Icon Naming Specification

DEPENDS+=	p5-XML-Simple>=2.14:../../textproc/p5-XML-Simple

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none, not even C
USE_TOOLS+=	gmake intltool perl:run

.include "../../mk/bsd.pkg.mk"
