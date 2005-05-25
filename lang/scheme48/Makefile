# $NetBSD: Makefile,v 1.25 2005/05/25 22:31:06 rillig Exp $

DISTNAME=		scheme48-1.2
CATEGORIES=		lang
MASTER_SITES=		http://s48.org/1.2/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://s48.org/
COMMENT=		The Scheme Underground's implementation of R5RS

NOT_FOR_PLATFORM=	*-*-alpha	# *severe* problems.  Bus error, alignment

GNU_CONFIGURE=  	yes
BUILD_TARGET=		enough

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/scheme48
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.txt *.ps 			\
		${PREFIX}/share/doc/scheme48
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/scheme48
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/scheme48
	${INSTALL_DATA} ${WRKSRC}/doc/html/* ${PREFIX}/share/doc/html/scheme48

.include "../../mk/bsd.pkg.mk"
