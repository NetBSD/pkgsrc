# $NetBSD: Makefile,v 1.5 2002/12/22 17:05:51 jmmv Exp $
# FreeBSD: ports/audio/xmp/Makefile,v 1.5 2000/04/08 21:24:59 mharo Exp
#

DISTNAME=	xmp-2.0.4
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://xmp.sourceforge.net/
COMMENT=	Player for many different Amiga and PC module formats

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-alsa \
		--disable-oss \
		--disable-xmms \
		--sysconfdir=${PKG_SYSCONFDIR}

USE_X11=	yes
USE_GMAKE=	yes

EGDIR=		${PREFIX}/share/examples/xmp
CONF_FILES=	${EGDIR}/xmp-modules.conf ${PKG_SYSCONFDIR}/xmp-modules.conf
CONF_FILES+=	${EGDIR}/xmp.conf ${PKG_SYSCONFDIR}/xmp.conf

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
