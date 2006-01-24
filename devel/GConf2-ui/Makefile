# $NetBSD: Makefile,v 1.23 2006/01/24 07:32:00 wiz Exp $
#

.include "../../devel/GConf2/Makefile.common"

PKGNAME=	${DISTNAME:S/GConf/GConf2-ui/}
PKGREVISION=	1

BUILDLINK_DEPENDS.GConf2+=	GConf2>=2.12.1

CONFIGURE_ARGS+=	--enable-gtk

BUILD_DIRS=	${WRKSRC}/gconf
BUILD_TARGET=	gconfmarshal.h gconfmarshal.c GConfX.h gconf-sanity-check-2

INSTALLATION_DIRS=	libexec

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gconf/.libs/gconf-sanity-check-2 \
		${PREFIX}/libexec

.include "../../devel/GConf2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
