# $NetBSD: Makefile,v 1.42 2008/01/19 09:16:20 wiz Exp $
#

DISTNAME=	angband-3.0.3
PKGNAME=	angband-x11-3.0.3
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	ftp://clockwork.dementia.org/angband/Source/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${SPOILERFILE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.thangorodrim.net/
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

SUBST_CLASSES+=		070
SUBST_STAGE.070=	pre-configure
SUBST_MESSAGE.070=	Fixing file permissions.
SUBST_FILES.070=	lib/save/Makefile.in lib/bone/Makefile.in
SUBST_SED.070=		-e 's,070,770,g'

# add spoiler files and clean up a bit
post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/games/angband/lib/info
	cd ${PREFIX}/share/games/angband/lib/info/ && \
		 ${PAX} -O -zrf ${DISTDIR}/${SPOILERFILE}
	${CHOWN} -R bin:games ${PREFIX}/share/games/angband
	${FIND} ${PREFIX}/share/games/angband -name delete.me -exec ${RM} {} \;

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/ncurses/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
