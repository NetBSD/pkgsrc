# $NetBSD: Makefile,v 1.19 2009/06/30 00:07:16 joerg Exp $
#

DISTNAME=	sarien-0.7.0
PKGREVISION=	7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sarien/}

MAINTAINER=	mor@linex.com
HOMEPAGE=	http://sarien.sourceforge.net/
COMMENT=	Adventure Game Interpreter (AGI) for Sierra On-Line Titles

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--with-sdl

CFLAGS+=		-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""
EGDIR=			${PREFIX}/share/examples/sarien
CONF_FILES=		${EGDIR}/sarien.conf ${PKG_SYSCONFDIR}/sarien.conf

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/sarien ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/sarien
	${INSTALL_DATA} ${WRKSRC}/doc/README* ${DESTDIR}${PREFIX}/share/doc/sarien
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/sarien.cfg ${DESTDIR}${EGDIR}/sarien.conf

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
