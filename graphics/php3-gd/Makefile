# $NetBSD: Makefile,v 1.5 2003/06/25 22:52:55 jmc Exp $

MODNAME=		gd
CATEGORIES+=		graphics
PKGREVISION=		2
COMMENT=		PHP3 extension for GD graphics library

USE_BUILDLINK2=		yes

.include "../../www/php3/Makefile.module"

CONFIGURE_ARGS+=	--with-gd
MOD_LIBS+=		-lgd -lintl -ljpeg -lpng -lttf -lm -lz

PLIST_SRC+=		${.CURDIR}/PLIST.extras

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/extra/gd/bdf2gdfont ${PREFIX}/bin

.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../graphics/gd/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
