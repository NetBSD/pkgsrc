# $NetBSD: Makefile,v 1.4 2003/06/02 01:18:59 jschauma Exp $

DISTNAME=	minischeme
PKGNAME=	minischeme-0.85
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/scheme-repository/imp/

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Very tiny scheme interpreter

post-extract:
	${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/miniscm ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/minischeme
	for i in init.scm nextleaf.scm tools.scm; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/minischeme; \
	done

.include "../../mk/bsd.pkg.mk"
