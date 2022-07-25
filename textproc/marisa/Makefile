# $NetBSD: Makefile,v 1.4 2022/07/25 11:12:29 wiz Exp $

.include "Makefile.common"
COMMENT=		C++ library to provide an implementation of MARISA

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake
USE_LANGUAGES=	c c++

#TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	marisa.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf --install --symlink

.include "../../mk/bsd.pkg.mk"
