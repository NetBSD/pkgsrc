# $NetBSD: Makefile,v 1.35 2023/01/29 21:15:39 ryoon Exp $
#

DISTNAME=	quirc-0.9.84
PKGREVISION=	12
CATEGORIES=	chat
#MASTER_SITES=	http://quirc.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://quirc.org/
COMMENT=	Stable and powerful graphical IRC client

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake automake autoconf autoreconf wish

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-wish=${TOOLS_PATH.wish}
MAKE_FLAGS+=		docdir=${PREFIX}/share/doc/quirc

SUBST_CLASSES+=		T86
SUBST_STAGE.T86=	pre-configure
SUBST_FILES.T86=	configure configure.in
SUBST_MESSAGE.T86=	Changing tcl/tk 8.3 search into tcl/tk 8.6 search
SUBST_SED.T86=		-e 's,8_3,8_6,g'
SUBST_SED.T86+=		-e 's,8.3,8.6,g'
SUBST_SED.T86+=		-e 's,83,86,g'

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	share/doc/quirc
INSTALLATION_DIRS+=	share/quirc
INSTALLATION_DIRS+=	share/quirc/common
INSTALLATION_DIRS+=	share/quirc/themes

pre-configure:
	cd ${WRKSRC} && autoreconf -i

# move default.tcl to themes/default.tcl and install to common/install.tcl
post-install:
	${MV} ${DESTDIR}${PREFIX}/share/quirc/default.tcl \
		${DESTDIR}${PREFIX}/share/quirc/themes
	${MV} ${DESTDIR}${PREFIX}/share/quirc/install.tcl \
		${DESTDIR}${PREFIX}/share/quirc/common

BUILDLINK_DEPMETHOD.libXt?=	build

CPPFLAGS+=	-DUSE_INTERP_RESULT

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
