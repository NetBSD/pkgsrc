# $NetBSD: Makefile,v 1.2 2002/11/01 04:18:02 rh Exp $
#

DISTNAME=	btparse-0.33
CATEGORIES=	textproc
MASTER_SITES=	http://starship.python.net/~gward/btOOL/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://starship.python.net/~gward/btOOL/
COMMENT=	BibTeX parsing library

USE_PERL5=	build
USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
ALL_TARGET=	lib

test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} test | \
		tee ${WRKDIR}/test.log

.include "../../mk/bsd.pkg.mk"
