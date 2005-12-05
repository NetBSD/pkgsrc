# $NetBSD: Makefile,v 1.37 2005/12/05 20:50:15 rillig Exp $
#

DISTNAME=	angband-3.0.3
PKGNAME=	angband-x11-3.0.3
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	ftp://clockwork.dementia.org/angband/Source/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${SPOILERFILE}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://thangorodrim.angband.org/
COMMENT=	Tolkien based variant of Moria for X11 displays

CONFLICTS=	angband-tty-[0-9]*

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

INCOMPAT_CURSES=	NetBSD-1.5*-* NetBSD-1.6[-_.]*-*
INCOMPAT_CURSES+=	NetBSD-1.6[A-M]-*

SPOILERFILE=	angband-spoilers.tar.gz

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-setgid=games

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=		2.95.3
.endif

# add spoiler files and clean up a bit
post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/games/angband/lib/info
	cd ${PREFIX}/share/games/angband/lib/info/ && \
		 ${PAX} -O -zrf ${DISTDIR}/${SPOILERFILE}
	${CHOWN} -R bin:games ${PREFIX}/share/games/angband
	${FIND} ${PREFIX}/share/games/angband -name delete.me -exec ${RM} {} \;

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
