# $NetBSD: Makefile,v 1.40 2003/03/15 08:58:43 jmmv Exp $

DISTNAME=		esound-0.2.29
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/esound/0.2/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.tux.org/~ricdude/EsounD.html
COMMENT=		the Enlightened sound daemon

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/esound.pc.in

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
MAKE_ENV+=		AM_CPPFLAGS='-DDEV_DSP=\"${DEVOSSAUDIO}\"'

EGDIR=			${PREFIX}/share/examples/esound
CONF_FILES=		${EGDIR}/esd.conf ${PKG_SYSCONFDIR}/esd.conf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/esound
	cd ${WRKSRC}/docs/html && \
		${PAX} -rwpppm . ${PREFIX}/share/doc/html/esound

.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
