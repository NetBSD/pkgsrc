# $NetBSD: Makefile,v 1.1.1.1 1999/09/10 15:48:02 rh Exp $
#

DISTNAME=	snort-1.2.1
CATEGORIES=	net security
MASTER_SITES=	http://www.clark.net/~roesch/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.clark.net/~roesch/security.html

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snort
.for file in README NEWS RULES.SAMPLE USAGE
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/snort
.endfor

.include "../../mk/bsd.pkg.mk"
