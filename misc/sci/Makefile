# $NetBSD: Makefile,v 1.7 2001/02/17 18:09:23 wiz Exp $
#

DISTNAME=	sci-0.5.6
CATEGORIES=	misc
MASTER_SITES=	http://linuxparts.com/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://linuxparts.com/software.html
COMMENT=	Curses based data entry via templates

GNU_CONFIGURE=	# Yupp

post-install:
	${MKDIR} ${PREFIX}/share/doc/sci ${PREFIX}/share/examples/sci
	for i in COPYING README INSTALL NEWS ; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/sci ; \
	   done
	for i in samples/* ; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/examples/sci ; \
	   done

.include "../../mk/bsd.pkg.mk"
