# $NetBSD: Makefile,v 1.30 2012/10/02 23:48:02 asau Exp $

DISTNAME=	openal-0.0.8
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openal.org/
COMMENT=	3D positional spatialized sound library
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake makeinfo
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PTHREAD_AUTO_VARS=	yes

INFO_FILES=		yes
INSTALLATION_DIRS=	${PKGINFODIR} include/AL
PKGCONFIG_OVERRIDE=	admin/pkgconfig/openal.pc.in
REPLACE_SH=		admin/pkgconfig/openal-config.in
LIBS+=			${LIBOSSAUDIO}

CPPFLAGS.SunOS+=	-D__EXTENSIONS__

SUBST_CLASSES+=		fixdev
SUBST_STAGE.fixdev=	post-configure
SUBST_FILES.fixdev=	src/backends/alc_backend_bsd.c
SUBST_SED.fixdev=	-e 's;/dev/dsp;${DEVOSSSOUND};g'

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
