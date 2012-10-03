# $NetBSD: Makefile,v 1.11 2012/10/03 21:56:10 wiz Exp $
#

DISTNAME=	icon-naming-utils-0.8.90
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://tango.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tango.freedesktop.org/
COMMENT=	Adapts GNOME and KDE icon names to the Icon Naming Specification

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-XML-Simple>=2.14:../../textproc/p5-XML-Simple

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none, not even C
USE_TOOLS+=	gmake intltool perl:run

.include "../../mk/bsd.pkg.mk"
