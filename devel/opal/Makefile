# $NetBSD: Makefile,v 1.19 2012/09/22 13:48:16 ryoon Exp $
#

DISTNAME=		opal-3.6.6
PKGREVISION=		3
CATEGORIES=		devel net comms
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/opal/3.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.opalvoip.org/
COMMENT=		Open Phone Abstraction Library
LICENSE=		mpl-1.0

PKG_DESTDIR_SUPPORT=	user-destdir
PREV_PKGPATH=		devel/opal-devel

OPALLIBDIR=		${DISTNAME}

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
BUILD_TARGET=		opt

CONFIGURE_ARGS+=	--enable-h264
# ekiga developers say that the ffmpeg-h263 plugin is
# not used and should be disabled in favour of the
# h263+ plugin, so do so
CONFIGURE_ARGS+=	--disable-ffmpeg-h263
CONFIGURE_ARGS+=	--disable-localgsm
CONFIGURE_ARGS+=	--disable-localspeex

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
USE_TOOLS+=		pkg-config

PLIST_SUBST+=		OPALLIBDIR=${OPALLIBDIR:Q}

.if "${MACHINE_ARCH}" == "i386"
PLIST_SUBST+=		LIBARCH=x86
.else
PLIST_SUBST+=		LIBARCH=${MACHINE_ARCH:Q}
.endif

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/opal
	${INSTALL_DATA} ${WRKSRC}/opal_inc.mak ${DESTDIR}${PREFIX}/share/opal
	${INSTALL_DATA} ${WRKSRC}/version.h ${DESTDIR}${PREFIX}/share/opal

# pkgsrc's gsm is shlib, need additional linker flags.
GSM_LIBS=		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gsm}/lib
GSM_LIBS+=		-L${BUILDLINK_PREFIX.gsm}/lib -lgsm
SUBST_CLASSES+=		gsm
SUBST_STAGE.gsm=	pre-configure
SUBST_FILES.gsm=	plugins/configure
SUBST_SED.gsm=		-e 's;GSM_LIBS="-lgsm";GSM_LIBS="${GSM_LIBS}";g'

#for WAV49
BUILDLINK_API_DEPENDS.gsm+=	gsm>=1.0.12
.include "../../audio/gsm/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../devel/ptlib/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../multimedia/x264-devel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
