# $NetBSD: Makefile,v 1.11 2004/01/12 10:02:39 cjep Exp $

DISTNAME=		vslisp-4.0-1
PKGNAME=		vslisp-4.0.1
PKGREVISION=		1
WRKSRC=			${WRKDIR}/vslisp-4.0
CATEGORIES=		lang
MASTER_SITES=		ftp://vslisp.sourceforge.net/pub/vslisp/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://vslisp.sourceforge.net/
COMMENT=		Embeddable Lisp library and standalone interpreter

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE= 	${WRKSRC}/ltconfig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vslisp
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vslisp/html
	@for d in Colors.txt ColorsDemo.txt lisp.sgml ; do \
	${INSTALL_DATA} ${WRKSRC}/Documentation/$$d \
	${PREFIX}/share/doc/vslisp; done
	${INSTALL_DATA} ${WRKSRC}/Documentation/html/* \
	${PREFIX}/share/doc/vslisp/html

.include "../../mk/bsd.pkg.mk"
