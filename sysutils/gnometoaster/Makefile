# $NetBSD: Makefile,v 1.5 2003/05/05 19:05:19 jmmv Exp $
#

DISTNAME=	gtoaster1.0Beta5
PKGNAME=	gnometoaster-1.0Beta5
PKGREVISION=	1
WRKSRC=		${WRKDIR}/gtoaster
CATEGORIES=	sysutils
MASTER_SITES=	http://gnometoaster.rulez.org/archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gnometoaster.rulez.org/
COMMENT=	cd recording frontend for X/Gtk

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_GMAKE=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-oss --without-esd
CONFIGURE_ARGS+=	--without-gnome --without-orbit

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
