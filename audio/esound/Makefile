# $NetBSD: Makefile,v 1.83 2015/01/09 16:33:15 rumko Exp $

DISTNAME=		esound-0.2.41
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/esound/0.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.tux.org/~ricdude/EsounD.html
COMMENT=		The Enlightened sound daemon
LICENSE=		gnu-lgpl-v2

USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE=	esound.pc.in

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ENV+=		ac_cv_prog_JW=false

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
LDFLAGS.DragonFly+=	-lm
LDFLAGS.FreeBSD+=	-lm
LDFLAGS.SunOS+=		-lm -lsocket -lnsl

REPLACE_SH+=		esd-config.in

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
