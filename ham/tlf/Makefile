# $NetBSD: Makefile,v 1.17 2012/10/03 13:01:45 asau Exp $
#

DISTNAME=	tlf-0.9.30
CATEGORIES=	ham
MASTER_SITES=	http://sharon.pi8zaa.ampr.org/pub/linux/ham/tlf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.iae.nl/users/reinc/TLF-0.2.html
COMMENT=	Advanced hamradio logging and contest program

USE_NCURSES=	yes
USE_TOOLS+=	gmake msgfmt
GNU_CONFIGURE=	yes
PTHREAD_OPTS+=	require
PTHREAD_AUTO_VARS=	yes

CONFIGURE_ARGS+=	--enable-hamlib

INSTALLATION_DIRS+=	share/tlf

post-patch:
	${ECHO} SC_DEVICE=/dev/tty00 >> ${WRKSRC:Q}/share/logcfg.dat

.include "../../mk/bsd.prefs.mk"

LIBS+=		${LIBOSSAUDIO}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
