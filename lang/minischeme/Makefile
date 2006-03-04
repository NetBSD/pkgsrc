# $NetBSD: Makefile,v 1.7 2006/03/04 21:29:55 jlam Exp $

DISTNAME=	minischeme
PKGNAME=	minischeme-0.85
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/scheme-repository/imp/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Very tiny scheme interpreter

INSTALLATION_DIRS=	bin

post-extract:
	${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/miniscm ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/minischeme
	for i in init.scm nextleaf.scm tools.scm; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/minischeme; \
	done

.include "../../mk/bsd.pkg.mk"
