# $NetBSD: Makefile,v 1.18 2012/10/03 00:02:46 asau Exp $

DISTNAME=	tkirc1.202
PKGNAME=	tkirc-1.202
PKGREVISION=	1
CATEGORIES=	chat x11
MASTER_SITES=	ftp://ftp.informatik.uni-oldenburg.de/pub/tkirc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://web.archive.org/web/20051221091126/http://netsplit.de/tkirc1/
COMMENT=	GUI for the ircII Internet Relay Chat client

DEPENDS+=	ircII-[0-9]*:../../chat/ircII
DEPENDS+=	tk>=8.3.2:../../x11/tk

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/tkirc
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkirc ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/tkircrc-example \
		${DESTDIR}${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DESTDIR}${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/tkirc

.include "../../mk/bsd.pkg.mk"
