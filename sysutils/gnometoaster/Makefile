# $NetBSD: Makefile,v 1.10 2004/01/20 12:26:15 agc Exp $
#

DISTNAME=	gtoaster1.0Beta5
PKGNAME=	gnometoaster-1.0Beta5
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://gnometoaster.rulez.org/archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gnometoaster.rulez.org/
COMMENT=	Cd recording frontend for X/Gtk

WRKSRC=			${WRKDIR}/gtoaster
USE_BUILDLINK2=		YES
USE_X11=		YES
USE_GMAKE=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-oss --without-esd
CONFIGURE_ARGS+=	--without-gnome --without-orbit

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
