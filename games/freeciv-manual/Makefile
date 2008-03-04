# $NetBSD: Makefile,v 1.13 2008/03/04 06:59:04 jlam Exp $
#

DISTNAME=	manual-1.8.1-2
PKGNAME=	freeciv-manual-1.8.1.2
CATEGORIES=	games
MASTER_SITES=	http://www.freeciv.org/ftp/contrib/manual/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freeciv.org/
COMMENT=	Manuals for freeciv (game, client, and server)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/manual
NO_BUILD=	YES

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/html/freeciv/img
	cd ${WRKSRC} && \
	${INSTALL_DATA} *.html ${DESTDIR}${PREFIX}/share/doc/html/freeciv
	cd ${WRKSRC}/img && \
	${INSTALL_DATA} *.jpg ${DESTDIR}${PREFIX}/share/doc/html/freeciv/img

.include "../../mk/bsd.pkg.mk"
