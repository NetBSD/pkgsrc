# $NetBSD: Makefile,v 1.15 2004/09/21 16:44:50 jmmv Exp $
#

.include "../../devel/GConf2/Makefile.common"

PKGNAME=	${DISTNAME:S/GConf/GConf2-ui/}

CONFIGURE_ARGS+=	--enable-gtk

BUILD_DIRS=	${WRKSRC}/gconf
ALL_TARGET=	gconfmarshal.h gconfmarshal.c GConfX.h gconf-sanity-check-2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gconf/.libs/gconf-sanity-check-2 \
		${PREFIX}/libexec

.include "../../devel/GConf2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
