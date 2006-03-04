# $NetBSD: Makefile,v 1.19 2006/03/04 21:30:41 jlam Exp $
#

DISTNAME=	gtoaster1.0Beta5
PKGNAME=	gnometoaster-1.0Beta5
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://gnometoaster.rulez.org/archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnometoaster.rulez.org/
COMMENT=	CD recording frontend for X/GTK+

WRKSRC=			${WRKDIR}/gtoaster
USE_TOOLS+=		gmake

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-oss --without-esd
CONFIGURE_ARGS+=	--without-gnome --without-orbit

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
