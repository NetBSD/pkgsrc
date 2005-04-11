# $NetBSD: Makefile,v 1.2 2005/04/11 21:46:03 tv Exp $
#

DISTNAME=	gnome-backgrounds-2.10.0
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-backgrounds/2.10/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Set of background images for the GNOME Desktop

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.1
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		# empty
USE_PKGLOCALEDIR=	YES

.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
