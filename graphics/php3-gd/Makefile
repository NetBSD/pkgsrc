# $NetBSD: Makefile,v 1.1.1.1 2002/01/10 13:06:44 jlam Exp $

MODNAME=		gd
CATEGORIES+=		graphics
PKGREVISION=		# empty
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
