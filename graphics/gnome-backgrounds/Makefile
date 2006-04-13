# $NetBSD: Makefile,v 1.13 2006/04/13 18:23:33 jlam Exp $
#

DISTNAME=	gnome-backgrounds-2.14.0
PKGREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-backgrounds/2.14/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Set of background images for the GNOME Desktop

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.3
USE_TOOLS+=		gmake msgfmt
USE_LANGUAGES=		# empty
USE_PKGLOCALEDIR=	YES

BUILDLINK_DEPMETHOD.gettext=	build

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
