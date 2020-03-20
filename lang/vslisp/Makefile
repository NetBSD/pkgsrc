# $NetBSD: Makefile,v 1.22 2020/03/20 11:57:56 nia Exp $

DISTNAME=	vslisp-4.0-1
PKGNAME=	vslisp-4.0.1
PKGREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vslisp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://vslisp.sourceforge.net/
COMMENT=	Embeddable Lisp library and standalone interpreter

# funcs.c:153:17: error: use of undeclared identifier 'r'
# funct.c:336:15: error: expected expression
# and similar
MAKE_JOBS_SAFE=	no

WRKSRC=		${WRKDIR}/vslisp-4.0
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/vslisp
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/vslisp/html
	@for d in Colors.txt ColorsDemo.txt lisp.sgml ; do \
		${INSTALL_DATA} ${WRKSRC}/Documentation/$$d \
		${DESTDIR}${PREFIX}/share/doc/vslisp; done
	${INSTALL_DATA} ${WRKSRC}/Documentation/html/* \
		${DESTDIR}${PREFIX}/share/doc/vslisp/html

.include "../../mk/bsd.pkg.mk"
