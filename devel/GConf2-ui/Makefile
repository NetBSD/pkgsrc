# $NetBSD: Makefile,v 1.16 2004/10/03 00:13:24 tv Exp $
#

.include "../../devel/GConf2/Makefile.common"

PKGNAME=	${DISTNAME:S/GConf/GConf2-ui/}
PKGREVISION=	1

CONFIGURE_ARGS+=	--enable-gtk

BUILD_DIRS=	${WRKSRC}/gconf
ALL_TARGET=	gconfmarshal.h gconfmarshal.c GConfX.h gconf-sanity-check-2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gconf/.libs/gconf-sanity-check-2 \
		${PREFIX}/libexec

.include "../../devel/GConf2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
