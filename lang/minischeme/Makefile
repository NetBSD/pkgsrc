# $NetBSD: Makefile,v 1.2 2001/02/17 09:07:20 agc Exp $

DISTNAME=	minischeme
PKGNAME=	minischeme-0.85
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/scheme-repository/imp/

MAINTAINER=	packages@netbsd.org
COMMENT=	Very tiny scheme interpreter

post-extract:
	${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/miniscm ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/minischeme
	for i in init.scm nextleaf.scm tools.scm; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/minischeme; \
	done

.include "../../mk/bsd.pkg.mk"
