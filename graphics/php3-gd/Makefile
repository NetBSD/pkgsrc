# $NetBSD: Makefile,v 1.2 2002/03/13 17:37:15 fredb Exp $

MODNAME=		gd
CATEGORIES+=		graphics
PKGREVISION=		1
COMMENT=		PHP3 extension for GD graphics library

USE_BUILDLINK_ONLY=	yes

.include "../../www/php3/Makefile.module"

CONFIGURE_ARGS+=	--with-gd
MOD_LIBS+=		-lgd -lintl -ljpeg -lpng -lttf -lm -lz

PLIST_SRC+=		${.CURDIR}/PLIST.extras

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/extra/gd/bdf2gdfont ${PREFIX}/bin

.include "../../graphics/gd/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
