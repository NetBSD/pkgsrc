# $NetBSD: Makefile,v 1.6 2003/07/17 21:46:58 grant Exp $
#

DISTNAME=	qtools-0.56
CATEGORIES=	mail
MASTER_SITES=	http://www.superscript.com/qtools/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.superscript.com/qtools/intro.html
COMMENT=	utilities for filtering via .qmail

DEPENDS+=	ezmlm>=0.53:../../mail/ezmlm

ALL_TARGET=	it
INSTALL_TARGET=	setup check

pre-build:
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home

.include "../../mk/bsd.pkg.mk"
