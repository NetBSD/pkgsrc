# $NetBSD: Makefile,v 1.19 2005/03/22 15:55:26 jmmv Exp $
#

.include "../../devel/GConf2/Makefile.common"

PKGNAME=	${DISTNAME:S/GConf/GConf2-ui/}

BUILDLINK_DEPENDS.GConf2+=	GConf2>=2.10.0

CONFIGURE_ARGS+=	--enable-gtk

BUILD_DIRS=	${WRKSRC}/gconf
BUILD_TARGET=	gconfmarshal.h gconfmarshal.c GConfX.h gconf-sanity-check-2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gconf/.libs/gconf-sanity-check-2 \
		${PREFIX}/libexec

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
