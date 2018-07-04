# $NetBSD: Makefile,v 1.29 2018/07/04 13:40:37 jperkin Exp $
#

DISTNAME=	gtoaster1.0Beta5
PKGNAME=	gnometoaster-1.0Beta5
PKGREVISION=	6
CATEGORIES=	sysutils
#MASTER_SITES=	# http://gnometoaster.rulez.org/archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://gnometoaster.rulez.org/
COMMENT=	CD recording frontend for X/GTK+

WRKSRC=			${WRKDIR}/gtoaster
USE_TOOLS+=		gmake

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-oss --without-esd
CONFIGURE_ARGS+=	--without-gnome --without-orbit

LDFLAGS.DragonFly=	-lintl

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	audio_oss.c
SUBST_SED.paths+=	-e 's,@DEVOSSAUDIO@,${DEVOSSAUDIO},g'
SUBST_STAGE.paths=	pre-configure

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
