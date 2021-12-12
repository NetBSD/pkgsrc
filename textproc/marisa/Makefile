# $NetBSD: Makefile,v 1.3 2021/12/12 13:55:13 taca Exp $

.include "Makefile.common"
COMMENT=		C++ library to provide an implementation of MARISA

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config autoconf automake
USE_LANGUAGES=	c c++

#TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	marisa.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf --install --symlink

.include "../../mk/bsd.pkg.mk"
