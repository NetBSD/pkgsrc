# $NetBSD: Makefile,v 1.30 2007/07/09 17:16:39 drochner Exp $
#

.include "../../devel/GConf2/Makefile.common"

PKGREVISION=	1

PKGNAME=	${DISTNAME:S/GConf/GConf2-ui/}

BUILDLINK_API_DEPENDS.GConf2+=	GConf2>=${GCONF2_VERSION}

CONFIGURE_ARGS+=	--enable-gtk

BUILD_DIRS=	${WRKSRC}/gconf
BUILD_TARGET=	gconfmarshal.h gconfmarshal.c GConfX.h gconf-sanity-check-2

INSTALLATION_DIRS=	libexec

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gconf/.libs/gconf-sanity-check-2 \
		${DESTDIR}${PREFIX}/libexec

.include "../../devel/GConf2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
