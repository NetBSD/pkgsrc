# $NetBSD: Makefile,v 1.20 2006/03/06 22:16:53 joerg Exp $
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

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	audio_oss.c
SUBST_SED.paths+=	-e 's,@DEVOSSAUDIO@,${DEVOSSAUDIO},g'
SUBST_STAGE.paths=	post-patch

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
