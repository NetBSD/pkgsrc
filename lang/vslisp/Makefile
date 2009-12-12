# $NetBSD: Makefile,v 1.16 2009/12/12 21:36:55 asau Exp $

DISTNAME=		vslisp-4.0-1
PKGNAME=		vslisp-4.0.1
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		ftp://vslisp.sourceforge.net/pub/vslisp/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://vslisp.sourceforge.net/
COMMENT=		Embeddable Lisp library and standalone interpreter

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/vslisp-4.0
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/vslisp
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/vslisp/html
	@for d in Colors.txt ColorsDemo.txt lisp.sgml ; do \
		${INSTALL_DATA} ${WRKSRC}/Documentation/$$d \
		${DESTDIR}${PREFIX}/share/doc/vslisp; done
	${INSTALL_DATA} ${WRKSRC}/Documentation/html/* \
		${DESTDIR}${PREFIX}/share/doc/vslisp/html

.include "../../mk/bsd.pkg.mk"
