# $NetBSD: Makefile,v 1.54 2004/10/11 18:02:59 tv Exp $

DISTNAME=		esound-0.2.35
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/esound/0.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.tux.org/~ricdude/EsounD.html
COMMENT=		The Enlightened sound daemon

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	esound.pc.in

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

BUILD_DEFS+=		USE_INET6

EGDIR=			${PREFIX}/share/examples/esound
CONF_FILES=		${EGDIR}/esd.conf ${PKG_SYSCONFDIR}/esd.conf

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${OPSYS} == "Interix"
# no sound output device, but can support a remote esound server
CONFIGURE_ARGS+=	--disable-local-sound
.else
.include "../../mk/ossaudio.buildlink3.mk"
MAKE_ENV+=		AM_CPPFLAGS='-DDEV_DSP=\"${DEVOSSAUDIO}\"'
SUBST_CLASSES=		oss
SUBST_STAGE.oss=	post-patch
SUBST_FILES.oss=	configure
SUBST_SED.oss=		-e 's,-lossaudio,${LIBOSSAUDIO},g'
SUBST_MESSAGE.oss=	"Fixing oss."
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/esound
	cd ${WRKSRC}/docs/html && \
		${PAX} -rw -pp -pm . ${PREFIX}/share/doc/html/esound

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
