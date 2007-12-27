# $NetBSD: Makefile,v 1.4 2007/12/27 12:48:38 obache Exp $
#

DISTNAME=	jcabc2ps-src
PKGNAME=	jcabc2ps-20060106
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://ecf-guest.mit.edu/~jc/music/abc/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ecf-guest.mit.edu/~jc/music/abc/src/
COMMENT=	Music typesetting program for abc

WRKSRC=		${WRKDIR}/jcabc2ps

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1

PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jcabc2ps ${DESTDIR}${PREFIX}/bin/.
	${INSTALL_MAN} ${WRKSRC}/doc/jcabc2ps.d ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1/jcabc2ps.0

.include "../../mk/bsd.pkg.mk"
