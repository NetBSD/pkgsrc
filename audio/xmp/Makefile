# $NetBSD: Makefile,v 1.3 2001/03/05 16:40:11 wiz Exp $
# FreeBSD: ports/audio/xmp/Makefile,v 1.5 2000/04/08 21:24:59 mharo Exp
#

DISTNAME=	xmp-2.0.2
CATEGORIES=	audio
MASTER_SITES=	http://xmp.helllabs.org/pkg/2.0.2/ \
		http://xmp.linuxbox.com/pkg/2.0.2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://xmp.helllabs.org/
COMMENT=	Player for many different Amiga and PC module formats

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-alsa \
		--disable-oss \
		--disable-xmms

USE_X11=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
