# $NetBSD: Makefile,v 1.25 2024/05/06 08:40:27 jperkin Exp $
#

DISTNAME=	tlf-0.9.31-2
PKGNAME=	${DISTNAME:C/([0-9])-/\1./}
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	https://www.aydogan.net/distfiles/ham/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tlf.github.io/
COMMENT=	Advanced hamradio logging and contest program
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake msgfmt
GNU_CONFIGURE=		yes
PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes

# 0.9.31-2 -> 0.9.31
WRKSRC=		${WRKDIR}/${DISTNAME:C/-([0-9])$//}

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
