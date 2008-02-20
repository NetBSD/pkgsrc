# $NetBSD: Makefile,v 1.28 2008/02/20 10:04:24 rillig Exp $

DISTNAME=	allegro-4.2.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=alleg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
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

.if !empty(INSTALL_UNSTRIPPED:Uno:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	allegro_cv_prog_ld_s=no
.endif

SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	post-patch
SUBST_FILES.oss=	src/unix/uoss.c setup/setup.c
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_MESSAGE.oss=	Fixing hardcoded audio device.

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	src/unix/umodules.c src/unix/usystem.c
SUBST_SED.path=		-e "s,@@PREFIX@@,${PREFIX},g"
SUBST_MESSAGE.path=	Fixing hardcoded path.

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
