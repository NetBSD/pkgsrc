# $NetBSD: Makefile,v 1.1.1.1 2001/11/29 19:11:04 zuntum Exp $
#

DISTNAME=	qtools-0.56
CATEGORIES=	mail
MASTER_SITES=	http://www.superscript.com/qtools/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.superscript.com/qtools/intro.html
COMMENT=	utilities for filtering via .qmail

DEPENDS+=	ezmlm-*:../../mail/ezmlm

ALL_TARGET=	it
INSTALL_TARGET=	setup check

pre-build:
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home

.include "../../mk/bsd.pkg.mk"
