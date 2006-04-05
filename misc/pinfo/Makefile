# $NetBSD: Makefile,v 1.29 2006/04/05 22:54:59 jlam Exp $
#

DISTNAME=		pinfo-0.6.1
PKGREVISION=		5
CATEGORIES=		misc
MASTER_SITES=		http://zeus.polsl.gliwice.pl/~pborys/stable-version/

MAINTAINER=		fredb@NetBSD.org
HOMEPAGE=		http://zeus.polsl.gliwice.pl/~pborys/
COMMENT=		Przemek's Info Viewer

BUILD_USES_MSGFMT=	yes

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

CPPFLAGS+=		-DDFLT_INFOPATH="\"/usr/share/info:${PREFIX}/${PKGINFODIR}:${X11BASE}/${PKGINFODIR}:${LOCALBASE}/${PKGINFODIR}:/usr/local/info\""

EGDIR=			${PREFIX}/share/examples/pinfo
CONF_FILES=		${EGDIR}/pinforc ${PKG_SYSCONFDIR}/pinforc
INFO_FILES=		# PLIST
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR:Q}

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
