# $NetBSD: Makefile,v 1.10 2005/06/01 14:29:58 wiz Exp $

DISTNAME=	allegro-4.1.18
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=alleg/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://alleg.sourceforge.net/
COMMENT=	Allegro game programming library

USE_TOOLS+=		gmake
USE_X11=		yes
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

SUBST_CLASSES=		oss
SUBST_STAGE.oss=	post-patch
SUBST_FILES.oss=	src/unix/uoss.c setup/setup.c
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_MESSAGE.oss=	"Fixing harcoded audio device."

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
