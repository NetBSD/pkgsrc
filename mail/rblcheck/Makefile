# $NetBSD: Makefile,v 1.13 2006/03/04 21:30:02 jlam Exp $

DISTNAME=	rblcheck-1.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rblcheck/} \
		http://www.xnet.com/%7Eemarshal/rblcheck/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rblcheck.sourceforge.net/
COMMENT=	Command-line interface to Paul Vixie's RBL filter

DOCS=		BUGS CHANGES CREDITS INSTALL PLATFORMS TODO

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rblcheck ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rblcheck
	cd ${WRKSRC}/docs &&						\
		${INSTALL_DATA} ${DOCS} ${PREFIX}/share/doc/rblcheck

.include "../../mk/bsd.pkg.mk"
