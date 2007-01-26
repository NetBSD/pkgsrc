# $NetBSD: Makefile,v 1.20 2007/01/26 18:23:30 joerg Exp $

DISTNAME=	xmp-2.0.4
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://xmp.sourceforge.net/
COMMENT=	Player for many different Amiga and PC module formats

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-alsa \
		--disable-oss \
		--disable-xmms \
		--sysconfdir=${PKG_SYSCONFDIR:Q}

USE_TOOLS+=	gmake

EGDIR=		${PREFIX}/share/examples/xmp
CONF_FILES=	${EGDIR}/xmp-modules.conf ${PKG_SYSCONFDIR}/xmp-modules.conf
CONF_FILES+=	${EGDIR}/xmp.conf ${PKG_SYSCONFDIR}/xmp.conf

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" || ${OPSYS} == "Interix"
# No native support for these OS's, so use esound for audio output
.include "../../audio/esound/buildlink3.mk"
.endif

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
