# $NetBSD: Makefile,v 1.6 2012/02/16 15:37:55 hans Exp $
#

DISTNAME=	smirk-20080111
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://smirk.googlecode.com/
COMMENT=	Revival of the curses-based Rhapsody IRC client

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${DATADIR:Q}

USE_TOOLS+=		gmake
USE_NCURSES=		yes

DATADIR=		${PREFIX}/share/${PKGBASE}
HELP_DIR=		${DATADIR}/help
HELP_FILES=		clientcmnds.hlp irccmnds.hlp keys.hlp

LIBS.SunOS+=		-lsocket -lnsl

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/smirk ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${HELP_DIR}
.for fn in ${HELP_FILES}
	${INSTALL_DATA} ${WRKSRC}/help/${fn} ${DESTDIR}${HELP_DIR}
.endfor

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
