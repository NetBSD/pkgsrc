# $NetBSD: Makefile,v 1.11 2004/02/12 18:47:40 jmmv Exp $
#

.include "../../devel/GConf2/Makefile.common"

PKGNAME=	${DISTNAME:S/GConf/GConf2-ui/}
PKGREVISION=	3

CONFIGURE_ENV+=	PKG_USE_GTK=yes

BUILD_DIRS=	${WRKSRC}/gconf
BUILD_TARGETS=	GConfX.h gconf-sanity-check-2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gconf/.libs/gconf-sanity-check-2 \
		${PREFIX}/libexec

.include "../../devel/GConf2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
