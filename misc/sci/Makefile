# $NetBSD: Makefile,v 1.10 2003/07/17 21:49:53 grant Exp $
#

DISTNAME=	sci-0.5.6
CATEGORIES=	misc
MASTER_SITES=	http://linuxparts.com/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://linuxparts.com/software.html
COMMENT=	Curses based data entry via templates

GNU_CONFIGURE=	# Yupp

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sci ${PREFIX}/share/examples/sci
	for i in COPYING README INSTALL NEWS ; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/sci ; \
	   done
	for i in samples/* ; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/examples/sci ; \
	   done

.include "../../mk/bsd.pkg.mk"
