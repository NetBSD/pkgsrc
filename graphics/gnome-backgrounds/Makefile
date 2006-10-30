# $NetBSD: Makefile,v 1.18 2006/10/30 21:38:04 drochner Exp $
#

DISTNAME=	gnome-backgrounds-2.16.1
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-backgrounds/2.16/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Set of background images for the GNOME Desktop

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.3
USE_TOOLS+=		gmake intltool msgfmt
USE_LANGUAGES=		c
USE_PKGLOCALEDIR=	YES

BUILDLINK_DEPMETHOD.gettext=	build

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
