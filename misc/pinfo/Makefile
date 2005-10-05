# $NetBSD: Makefile,v 1.24 2005/10/05 13:29:49 wiz Exp $
#

DISTNAME=		pinfo-0.6.1
PKGREVISION=		3
CATEGORIES=		misc
MASTER_SITES=		http://zeus.polsl.gliwice.pl/~pborys/stable-version/

MAINTAINER=		fredb@NetBSD.org
HOMEPAGE=		http://zeus.polsl.gliwice.pl/~pborys/
COMMENT=		Przemek's Info Viewer

BUILD_USES_MSGFMT=	yes

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

INFO_FILES=	pinfo.info

CPPFLAGS=		-DDFLT_INFOPATH="\"/usr/share/info:${X11BASE}/info:${LOCALBASE}/info:/usr/local/info\""

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

CONF_FILES=	${PREFIX}/share/examples/pinfo/pinforc ${PKG_SYSCONFDIR}/pinforc

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/pinfo
	${INSTALL_DATA} ${WRKSRC}/src/pinforc ${PREFIX}/share/examples/pinfo

PKG_OPTIONS_VAR=	PKG_OPTIONS.pinfo
PKG_SUPPORTED_OPTIONS=	pinfo-native-curses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpinfo-native-curses)
CONFIGURE_ARGS+=	--with-vcurses
.else
.include "../../devel/ncurses/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ncurses=${BUILDLINK_PREFIX.ncurses}
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
