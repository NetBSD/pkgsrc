# $NetBSD: Makefile,v 1.1.1.1 2000/12/04 23:47:35 jtb Exp $

DISTNAME=		vslisp-4.0-1
PKGNAME=		vslisp-4.0.1
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.sourceforge.net/pub/sourceforge/vslisp/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://vslisp.sourceforge.net

WRKSRC=			${WRKDIR}/vslisp-4.0
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE= 	${WRKSRC}/ltconfig
LIBTOOL_OVERRIDE= 	${WRKSRC}/libtool

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vslisp
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vslisp/html
	@for d in Colors.txt ColorsDemo.txt lisp.sgml ; do \
	${INSTALL_DATA} ${WRKSRC}/Documentation/$$d \
	${PREFIX}/share/doc/vslisp; done
	${INSTALL_DATA} ${WRKSRC}/Documentation/html/* \
	${PREFIX}/share/doc/vslisp/html

.include "../../mk/bsd.pkg.mk"
