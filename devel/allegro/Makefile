# $NetBSD: Makefile,v 1.12 2005/09/11 14:17:44 wiz Exp $

DISTNAME=	allegro-4.1.18
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=alleg/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://alleg.sourceforge.net/
COMMENT=	Allegro game programming library

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

MAKEFILE=		makefile
BUILD_TARGET=		# there is no 'all' target for some reason
USE_MAKEINFO=		yes
INFO_FILES=		allegro.info
INSTALL_TARGET=		install install-info

# NetBSD's OSS midi emulation is non-existant.
CONFIGURE_ARGS+=	--disable-ossmidi

LIBS+=		${LIBOSSAUDIO}

.include "options.mk"

SUBST_CLASSES=		oss path
SUBST_STAGE.oss=	post-patch
SUBST_FILES.oss=	src/unix/uoss.c setup/setup.c
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_MESSAGE.oss=	"Fixing harcoded audio device."
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	src/unix/umodules.c src/unix/usystem.c
SUBST_SED.path=	-e "s,@@PREFIX@@,${PREFIX},g"
SUBST_MESSAGE.path=	"Fixing harcoded path"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
