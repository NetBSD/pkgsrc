# $NetBSD: Makefile,v 1.30 2022/06/28 11:33:56 wiz Exp $
#

DISTNAME=		netmaj-2.0.7
PKGREVISION=		14
CATEGORIES=		games
MASTER_SITES=		http://www.sfc.wide.ad.jp/~kusune/netmaj/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.sfc.wide.ad.jp/~kusune/netmaj/
COMMENT=		Mahjongg game with network and 1-4 player(s) support

WRKSRC=			${WRKDIR}/netmaj
USE_TOOLS+=		perl:run
HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		OPSYS=${OPSYS}
CONFIGURE_ENV+=		CURSES_LIBS=${BUILDLINK_LDADD.ncursesw:Q}

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

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
