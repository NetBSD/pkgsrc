# $NetBSD: Makefile,v 1.1.1.1 2002/05/04 01:15:25 jtb Exp $

DISTNAME=	nullmailer-1.00RC5
CATEGORIES=	mail
MASTER_SITES=	http://untroubled.org/nullmailer/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://untroubled.org/nullmailer/
COMMENT=	Simple relay-only mail transport agent

GNU_CONFIGURE=	# defined

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nullmailer
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS BUGS COPYING ChangeLog	\
		HOWTO NEWS README TODO ${PREFIX}/share/doc/nullmailer

.include "../../mk/bsd.pkg.mk"
