# $NetBSD: Makefile,v 1.19 2003/04/10 20:10:17 grant Exp $
#

DISTNAME=	angband-3.0.1
PKGNAME=	angband-x11-3.0.1
CATEGORIES=	games x11
MASTER_SITES=	ftp://clockwork.dementia.org/angband/Source/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${SPOILERFILE}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://thangorodrim.angband.org/
COMMENT=	Tolkien based variant of Moria for X11 displays

CONFLICTS=	angband-tty-[0-9]*

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_BUILDLINK2=	# defined
USE_X11=	# defined
USE_NCURSES=	# can_change_color

SPOILERFILE=	angband-spoilers.tar.gz

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-setgid=games --prefix=${PREFIX}

.if ${MACHINE_ARCH} == "arm32"
.  include "../../lang/gcc/buildlink2.mk"
.endif

# add spoiler files and clean up a bit
post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/games/angband/lib/info
	cd ${PREFIX}/share/games/angband/lib/info/ && \
		 ${PAX} -O -zrf ${DISTDIR}/${SPOILERFILE}
	${CHOWN} -R bin:games ${PREFIX}/share/games/angband
	${FIND} ${PREFIX}/share/games/angband -name delete.me -exec ${RM} {} \;

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
