# $NetBSD: Makefile,v 1.4 2003/05/02 11:56:24 wiz Exp $
#

DISTNAME=	gtoaster1.0Beta5
PKGREVISION=	1
PKGNAME=	gnometoaster-1.0Beta5
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
