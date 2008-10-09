# $NetBSD: Makefile,v 1.3 2008/10/09 20:53:48 wiz Exp $
#

.include "../../devel/GConf/Makefile.common"

PKGNAME=	${DISTNAME:S/GConf/GConf-ui/}

BUILDLINK_API_DEPENDS.GConf+=	GConf>=${GCONF_VERSION}

CONFIGURE_ARGS+=	--enable-gtk

BUILD_DIRS=	gconf
BUILD_TARGET=	gconfmarshal.h gconfmarshal.c GConfX.h gconf-sanity-check-2

INSTALLATION_DIRS=	libexec

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gconf/.libs/gconf-sanity-check-2 \
		${DESTDIR}${PREFIX}/libexec

.include "../../devel/GConf/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
