# $NetBSD: Makefile,v 1.12 2008/07/14 12:56:04 joerg Exp $

DISTNAME=		netmaze0.81
PKGNAME=		netmaze-0.81
PKGREVISION=		3
CATEGORIES=		games
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=games/multiplayer/}

MAINTAINER=		jdc@NetBSD.org
COMMENT=		X windows-based multiplayer combat game (like Midi Maze)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/netmaze
USE_IMAKE=		yes

post-patch:
	${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.bak
	${SED} -e 's|@X11LIBS@|${X11_LDFLAGS}|g' \
		< ${WRKSRC}/Imakefile.bak > ${WRKSRC}/Imakefile

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
