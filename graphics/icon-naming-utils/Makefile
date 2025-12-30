# $NetBSD: Makefile,v 1.24 2025/12/30 08:15:56 wiz Exp $

DISTNAME=	icon-naming-utils-0.8.90
PKGREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	http://tango.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://specifications.freedesktop.org/icon-naming/latest/
COMMENT=	Adapts GNOME and KDE icon names to the Icon Naming Specification

DEPENDS+=	p5-XML-Simple>=2.14:../../textproc/p5-XML-Simple

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none, not even C
USE_TOOLS+=	gmake perl:run

.include "../../mk/bsd.pkg.mk"
