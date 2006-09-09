# $NetBSD: Makefile,v 1.21 2006/09/09 02:41:56 obache Exp $

DISTNAME=	allegro-4.2.0
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=alleg/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://alleg.sourceforge.net/
COMMENT=	Allegro game programming library

USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes

MAKE_FILE=		makefile
BUILD_TARGET=		# there is no 'all' target for some reason
INFO_FILES=		YES
INSTALL_TARGET=		install install-info

# NetBSD's OSS midi emulation is non-existent.
CONFIGURE_ARGS+=	--disable-ossmidi

.include "options.mk"

SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	post-patch
SUBST_FILES.oss=	src/unix/uoss.c setup/setup.c
SUBST_SED.oss=		-e "s,/dev/dsp,"${DEVOSSAUDIO:Q}",g"
SUBST_MESSAGE.oss=	Fixing hardcoded audio device.

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
