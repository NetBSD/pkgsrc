# $NetBSD: Makefile,v 1.7 2001/04/22 22:18:10 zuntum Exp $
# FreeBSD: ports/mail/rblcheck/Makefile,v 1.6 1999/08/25 06:50:47 obrien Exp
#

DISTNAME=	rblcheck-1.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rblcheck/} \
		http://www.xnet.com/%7Eemarshal/rblcheck/

MAINTAINER=	itojun@itojun.org
HOMEPAGE=	http://rblcheck.sourceforge.net/
COMMENT=	Command-line interface to Paul Vixie's RBL filter

DOCS=		BUGS CHANGES CREDITS INSTALL PLATFORMS TODO

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rblcheck ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rblcheck
	cd ${WRKSRC}/docs &&						\
		${INSTALL_DATA} ${DOCS} ${PREFIX}/share/doc/rblcheck

.include "../../mk/bsd.pkg.mk"
