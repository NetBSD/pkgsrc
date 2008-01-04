# $NetBSD: Makefile,v 1.32 2008/01/04 07:49:35 obache Exp $
#

DISTNAME=		pinfo-0.6.1
PKGREVISION=		5
CATEGORIES=		misc
MASTER_SITES=		# http://alioth.debian.org/download.php/1502/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pinfo.alioth.debian.org/
COMMENT=		Przemek's Info Viewer

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
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
