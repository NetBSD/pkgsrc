# $NetBSD: Makefile,v 1.1.1.1 2003/07/29 16:17:41 agc Exp $

DISTNAME=	re2c-0.9.1
CATEGORIES=	devel
MASTER_SITES=	http://www.netsw.org/softeng/compilerconstruct/re2c/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.tildeslash.org/
COMMENT=	Deterministic Finite State Automaton generator

USE_GMAKE=	yes
ALL_TARGET=	default

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/re2c ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/re2c.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
