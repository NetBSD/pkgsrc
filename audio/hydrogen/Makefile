# $NetBSD: Makefile,v 1.1.1.1 2004/07/06 14:52:26 xtraeme Exp $

DISTNAME=	hydrogen-0.8.0
PKGNAME=	${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hydrogen/}

MAINTAINER=	chris.wareham@btinternet.com
HOMEPAGE=	http://hydrogen.sourceforge.net/
COMMENT=	Real time drum machine/sequencer

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-alsa-seq
CONFIGURE_ARGS+=	--disable-jack-support

.if exists(${X11BASE}/include/X11/extensions/Xinerama.h)
CONFIGURE_ARGS+=	--with-xinerama
.endif

.include "../../audio/libhydrogen/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
