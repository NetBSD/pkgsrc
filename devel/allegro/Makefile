# $NetBSD: Makefile,v 1.3 2004/10/03 00:13:24 tv Exp $
#

DISTNAME=	allegro-4.1.14
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=alleg/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://alleg.sourceforge.net/
COMMENT=	Allegro game programming library

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
GNU_CONFIGURE=		yes

MAKEFILE=		makefile
ALL_TARGET=		# there is no 'all' target for some reason
USE_MAKEINFO=		yes
INFO_FILES=		allegro.info
INSTALL_TARGET=		install install-info

# NetBSD's OSS midi emulation is non-existant.
CONFIGURE_ARGS+=	--disable-ossmidi

LIBS+=		${LIBOSSAUDIO}

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	USE_ESOUND

.if !empty(USE_ESOUND:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-esddigi
.include "../../audio/esound/buildlink3.mk"
.endif

SUBST_CLASSES=		oss
SUBST_STAGE.oss=	post-patch
SUBST_FILES.oss=	src/unix/uoss.c setup/setup.c
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_MESSAGE.oss=	"Fixing harcoded audio device."

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
