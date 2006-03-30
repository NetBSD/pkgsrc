# $NetBSD: Makefile,v 1.11 2006/03/30 21:17:48 jmmv Exp $
#

DISTNAME=	gnome-backgrounds-2.14.0
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-backgrounds/2.14/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Set of background images for the GNOME Desktop

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake
USE_LANGUAGES=		# empty
USE_PKGLOCALEDIR=	YES

BUILDLINK_DEPMETHOD.gettext=	build

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
