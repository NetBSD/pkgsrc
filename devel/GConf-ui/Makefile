# $NetBSD: Makefile,v 1.26 2013/06/03 10:04:42 wiz Exp $
#

MAKE_JOBS_SAFE=	no

.include "../../devel/GConf/Makefile.common"

PKGNAME=	${DISTNAME:S/GConf/GConf-ui/}
PKGREVISION=	9

BUILDLINK_API_DEPENDS.GConf+=	GConf>=${GCONF_VERSION}

CONFIGURE_ARGS+=	--enable-gtk
CONFIGURE_ARGS+=	--with-gtk=2.0
CONFIGURE_ARGS+=	--disable-defaults-service

BUILD_DIRS=	gconf
BUILD_TARGET=	gconfmarshal.h gconfmarshal.c GConfX.h gconf-sanity-check-2

INSTALLATION_DIRS=	libexec

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gconf/.libs/gconf-sanity-check-2 \
		${DESTDIR}${PREFIX}/libexec

.include "../../devel/GConf/buildlink3.mk"
#.include "../../security/policykit/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
