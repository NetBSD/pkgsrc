# $NetBSD: Makefile,v 1.10 2004/01/03 18:49:39 reed Exp $
#

DISTNAME=		gconf-editor-2.4.0
PKGREVISION=		1
CATEGORIES=		editors gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gconf-editor/2.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sab@posix.org.uk
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Editor for the GConf configuration system

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES
USE_X11=		YES

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
