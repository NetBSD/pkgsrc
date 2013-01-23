# $NetBSD: Makefile,v 1.1 2013/01/23 22:00:06 wiz Exp $

DISTNAME=	dhex_0.68
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	editors
MASTER_SITES=	http://dettus.net/dhex/

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://www.dettus.net/dhex/
COMMENT=	The ncurses-based hex-editor with diff mode
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c

MAN1=		dhex.1
MAN5=		dhexrc.5 dhex_markers.5 dhex_searchlog.5

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhex ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.for f in ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
.endfor

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
