# $NetBSD: Makefile,v 1.15 2018/01/01 23:12:09 rillig Exp $
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
AUTO_MKDIRS=	yes

do-install:
	cd ${WRKSRC} && \
	${INSTALL_DATA} *.html ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	cd ${WRKSRC}/img && \
	${INSTALL_DATA} *.jpg ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/img

.include "../../mk/bsd.pkg.mk"
