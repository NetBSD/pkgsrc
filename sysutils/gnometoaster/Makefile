# $NetBSD: Makefile,v 1.1.1.1 2002/03/25 11:24:28 drochner Exp $
#

DISTNAME=	gtoaster1.0Beta5
PKGNAME=	gnometoaster-1.0Beta5
CATEGORIES=	sysutils
MASTER_SITES=	http://gnometoaster.rulez.org/archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gnometoaster.rulez.org/
COMMENT=	cd recording frontend for X/Gtk

WRKSRC=		${WRKDIR}/gtoaster
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --with-oss --without-esd
CONFIGURE_ARGS+= --without-gnome --without-orbit
USE_LIBINTL=	yes
USE_GMAKE=	yes
USE_BUILDLINK_ONLY= yes

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
