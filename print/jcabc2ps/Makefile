# $NetBSD: Makefile,v 1.3 2006/12/15 14:34:20 wiz Exp $
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jcabc2ps ${PREFIX}/bin/.
	${INSTALL_DATA} ${WRKSRC}/doc/jcabc2ps.d ${PREFIX}/${PKGMANDIR}/cat1/jcabc2ps.0

.include "../../mk/bsd.pkg.mk"
