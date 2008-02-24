# $NetBSD: Makefile,v 1.1.1.1 2008/02/24 04:57:07 jlam Exp $

DISTNAME=	PDCurses-3.3
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	devel x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pdcurses/}

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://pdcurses.sourceforge.net/
COMMENT=	public domain implementation of the X/Open curses standard

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
MAKE_JOBS_SAFE=		no

CONFIGURE_ARGS+=	--with-x

# PDCURSES_XAW is the name of the Xaw library.
#
# XXX This information should really be provided by the various Xaw-like
# XXX buildlink3.mk files.
#
PDCURSES_XAW.3d=	Xaw3d
PDCURSES_XAW.neXtaw=	neXtaw
PDCURSES_XAW.xpm=	Xaw3d
PDCURSES_XAW.standard= 	Xaw
PDCURSES_XAW=		${PDCURSES_XAW.${XAW_TYPE}}
CONFIGURE_ENV+=		PDCURSES_XAW=${PDCURSES_XAW:Q}

REPLACE_SH=		x11/xcurses-config.in
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/PDCurses.txt ${DESTDIR}${DOCDIR}

.include "../../mk/xaw.buildlink3.mk"

.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
