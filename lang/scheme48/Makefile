# $NetBSD: Makefile,v 1.23 2004/12/03 15:15:01 wiz Exp $
# FreeBSD Id: Makefile,v 1.10 1997/08/27 19:31:37 jmacd Exp
#

DISTNAME=		scheme48-0.57
CATEGORIES=		lang
MASTER_SITES=		http://s48.org/0.57/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://s48.org/
COMMENT=		The Scheme Underground's implementation of R5RS

NOT_FOR_PLATFORM=	*-*-alpha	# *severe* problems.  Bus error, alignment

GNU_CONFIGURE=  	yes
CONFIGURE_ARGS=		--prefix=${PREFIX}
BUILD_TARGET=		enough

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/scheme48
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.txt *.ps 			\
		${PREFIX}/share/doc/scheme48
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/scheme48
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/scheme48
	${INSTALL_DATA} ${WRKSRC}/doc/html/* ${PREFIX}/share/doc/html/scheme48

.include "../../mk/bsd.pkg.mk"
