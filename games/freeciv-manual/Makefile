# $NetBSD: Makefile,v 1.16 2018/01/07 21:00:23 joerg Exp $
#

DISTNAME=	manual-1.8.1-2
PKGNAME=	freeciv-manual-1.8.1.2
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.freeciv.org/ftp/contrib/manual/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freeciv.org/
COMMENT=	Manuals for old Freeciv version (game, client, and server)

WRKSRC=		${WRKDIR}/manual
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/doc/freeciv-manual/img

do-install:
	cd ${WRKSRC} && \
	${INSTALL_DATA} *.html ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	cd ${WRKSRC}/img && \
	${INSTALL_DATA} *.jpg ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/img

.include "../../mk/bsd.pkg.mk"
