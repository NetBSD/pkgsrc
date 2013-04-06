# $NetBSD: Makefile,v 1.19 2013/04/06 14:09:33 rodent Exp $

DISTNAME=	vslisp-4.0-1
PKGNAME=	vslisp-4.0.1
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vslisp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://vslisp.sourceforge.net/
COMMENT=	Embeddable Lisp library and standalone interpreter

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
