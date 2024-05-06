# $NetBSD: Makefile,v 1.32 2024/05/06 08:40:26 jperkin Exp $
#

DISTNAME=		netmaj-2.0.7
PKGREVISION=		15
CATEGORIES=		games
MASTER_SITES=		http://www.sfc.wide.ad.jp/~kusune/netmaj/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.sfc.wide.ad.jp/~kusune/netmaj/
COMMENT=		Mahjongg game with network and 1-4 player(s) support

WRKSRC=			${WRKDIR}/netmaj
USE_TOOLS+=		perl:run
HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		OPSYS=${OPSYS}
CONFIGURE_ENV+=		CURSES_LIBS=${BUILDLINK_LDADD.ncurses:Q}

INSTALL_MAKE_FLAGS+=	PERL=${PERL5:Q}
INSTALL_TARGET=		install install-pf
DOCDIR=			${PREFIX}/share/doc/netmaj

pre-configure:
	cp ${FILESDIR}/configure.sh ${WRKSRC}/configure
	chmod +x ${WRKSRC}/configure
	chmod a-x ${WRKSRC}/auto.pf

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/html/* ${DESTDIR}${DOCDIR}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
