# $NetBSD: Makefile,v 1.12 2004/02/08 14:35:11 grant Exp $
#

DISTNAME=	gtoaster1.0Beta5
PKGNAME=	gnometoaster-1.0Beta5
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://gnometoaster.rulez.org/archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gnometoaster.rulez.org/
COMMENT=	CD recording frontend for X/GTK+

WRKSRC=			${WRKDIR}/gtoaster
USE_BUILDLINK2=		YES
USE_X11=		YES
USE_GNU_TOOLS+=		make

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-oss --without-esd
CONFIGURE_ARGS+=	--without-gnome --without-orbit

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
