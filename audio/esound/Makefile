# $NetBSD: Makefile,v 1.68 2008/01/19 09:16:17 wiz Exp $

DISTNAME=		esound-0.2.38
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/esound/0.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.tux.org/~ricdude/EsounD.html
COMMENT=		The Enlightened sound daemon

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE=	esound.pc.in

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=			${PREFIX}/share/examples/esound
CONF_FILES=		${EGDIR}/esd.conf ${PKG_SYSCONFDIR}/esd.conf

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Interix"
# no sound output device, but can support a remote esound server
CONFIGURE_ARGS+=	--disable-local-sound
.else
.include "../../mk/oss.buildlink3.mk"
MAKE_ENV+=		AM_CPPFLAGS='-DDEV_DSP=\"${DEVOSSAUDIO}\"'
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	post-patch
SUBST_FILES.oss=	configure
SUBST_SED.oss=		-e 's,-lossaudio,${LIBOSSAUDIO},g'
SUBST_MESSAGE.oss=	Fixing oss.
.endif

LDFLAGS.IRIX+=		-lm

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
