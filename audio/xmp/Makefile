# $NetBSD: Makefile,v 1.10 2004/10/03 00:13:12 tv Exp $
# FreeBSD: ports/audio/xmp/Makefile,v 1.5 2000/04/08 21:24:59 mharo Exp
#

DISTNAME=	xmp-2.0.4
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://xmp.sourceforge.net/
COMMENT=	Player for many different Amiga and PC module formats

USE_PKGINSTALL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-alsa \
		--disable-oss \
		--disable-xmms \
		--sysconfdir=${PKG_SYSCONFDIR}

USE_X11=	yes
USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	yes

EGDIR=		${PREFIX}/share/examples/xmp
CONF_FILES=	${EGDIR}/xmp-modules.conf ${PKG_SYSCONFDIR}/xmp-modules.conf
CONF_FILES+=	${EGDIR}/xmp.conf ${PKG_SYSCONFDIR}/xmp.conf

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
# XMP has no native Darwin support, so make it use the esound backend
.include "../../audio/esound/buildlink3.mk"
.endif

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

.include "../../mk/bsd.pkg.mk"
