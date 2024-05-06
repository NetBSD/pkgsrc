# $NetBSD: Makefile,v 1.40 2024/05/06 08:27:54 jperkin Exp $
#

DISTNAME=		pinfo-0.6.1
PKGREVISION=		8
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
INFO_FILES=		yes
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR:Q}

.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/curses.buildlink3.mk"
.if ${CURSES_TYPE} == "curses"
CONFIGURE_ARGS+=	--with-vcurses
.elif ${CURSES_TYPE} == "ncurses"
CONFIGURE_ARGS+=	--with-ncurses=${BUILDLINK_PREFIX.curses}
.endif

.include "../../mk/bsd.pkg.mk"
