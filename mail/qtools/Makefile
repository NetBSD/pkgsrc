# $NetBSD: Makefile,v 1.7 2003/07/21 16:56:55 martti Exp $
#

DISTNAME=	qtools-0.56
CATEGORIES=	mail
MASTER_SITES=	http://www.superscript.com/qtools/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.superscript.com/qtools/intro.html
COMMENT=	Utilities for filtering via .qmail

DEPENDS+=	ezmlm>=0.53:../../mail/ezmlm

ALL_TARGET=	it
INSTALL_TARGET=	setup check

pre-build:
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home

.include "../../mk/bsd.pkg.mk"
