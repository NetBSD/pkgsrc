# $NetBSD: Makefile,v 1.3 2002/10/09 11:55:54 wiz Exp $

MODNAME=		gd
CATEGORIES+=		graphics
PKGREVISION=		1
COMMENT=		PHP3 extension for GD graphics library

USE_BUILDLINK2=		yes

.include "../../www/php3/Makefile.module"

CONFIGURE_ARGS+=	--with-gd
MOD_LIBS+=		-lgd -lintl -ljpeg -lpng -lttf -lm -lz

PLIST_SRC+=		${.CURDIR}/PLIST.extras

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/extra/gd/bdf2gdfont ${PREFIX}/bin

.include "../../graphics/gd/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
