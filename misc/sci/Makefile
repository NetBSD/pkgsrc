# $NetBSD: Makefile,v 1.6 2000/12/15 14:45:34 mjl Exp $
#

DISTNAME=	sci-0.5.6
CATEGORIES=	misc
MASTER_SITES=	http://linuxparts.com/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://linuxparts.com/software.html

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
