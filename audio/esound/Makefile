# $NetBSD: Makefile,v 1.46 2004/01/06 07:17:03 jlam Exp $

DISTNAME=		esound-0.2.32
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/esound/0.2/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.tux.org/~ricdude/EsounD.html
COMMENT=		The Enlightened sound daemon

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/esound.pc.in

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
MAKE_ENV+=		AM_CPPFLAGS='-DDEV_DSP=\"${DEVOSSAUDIO}\"'

EGDIR=			${PREFIX}/share/examples/esound
CONF_FILES=		${EGDIR}/esd.conf ${PKG_SYSCONFDIR}/esd.conf

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/esound
	cd ${WRKSRC}/docs/html && \
		${PAX} -rw -pp -pm . ${PREFIX}/share/doc/html/esound

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
