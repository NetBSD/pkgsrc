# $NetBSD: Makefile,v 1.35 2014/02/12 23:18:18 tron Exp $
#

DISTNAME=		mplayerplug-in-3.55
PKGNAME=		mplayer-plugin-3.55
PKGREVISION=		30
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mplayerplug-in/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mplayerplug-in.sourceforge.net/
COMMENT=		Mplayer plug-in for Gecko-based browsers

DEPENDS+=		mplayer>=0.92:../../multimedia/mplayer

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config msgfmt
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--enable-wmp
CONFIGURE_ARGS+=	--enable-qt
CONFIGURE_ARGS+=	--enable-rm
CONFIGURE_ARGS+=	--enable-gmp
CONFIGURE_ARGS+=	--enable-dvx
CONFIGURE_ARGS+=	--disable-gtk1
CONFIGURE_ENV+=		ac_cv_path_GECKO_XPIDL=${BUILDLINK_PREFIX.xulrunner192}/lib/xulrunner192/xpidl

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	Source/plugin-setup.cpp
SUBST_SED.conf=		-e "s|/etc/|${PKG_SYSCONFDIR}/|g"
SUBST_MESSAGE.conf=	Fixing harcoded paths.

EGDIR=		${PREFIX}/share/examples/mplayer-plugin
CONF_FILES=	# empty
.for f in conf types
CONF_FILES+=	${EGDIR}/mplayerplug-in.${f} \
		${PKG_SYSCONFDIR}/mplayerplug-in.${f}
.endfor

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/mplayerplug-in.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/mplayerplug-in.types ${DESTDIR}${EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/netscape/plugins
	${INSTALL_LIB} ${WRKSRC}/*.so	${DESTDIR}${PREFIX}/lib/netscape/plugins
	${INSTALL_DATA} ${WRKSRC}/*.xpt	${DESTDIR}${PREFIX}/lib/netscape/plugins

BUILDLINK_DEPMETHOD.xulrunner192=	build
.include "../../devel/xulrunner192/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
