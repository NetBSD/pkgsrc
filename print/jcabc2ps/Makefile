# $NetBSD: Makefile,v 1.1.1.1 2006/04/02 22:18:58 ben Exp $
#

DISTNAME=	jcabc2ps-src
PKGNAME=	jcabc2ps-20060106
CATEGORIES=	print
MASTER_SITES=	http://ecf-guest.mit.edu/~jc/music/abc/src/
WRKSRC=		${WRKDIR}/jcabc2ps

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://ecf-guest.mit.edu/~jc/music/abc/src/
COMMENT=	Music typesetting program for abc

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/jcabc2ps.d ${PREFIX}/man/cat1/jcabc2ps.1

.include "../../mk/bsd.pkg.mk"
