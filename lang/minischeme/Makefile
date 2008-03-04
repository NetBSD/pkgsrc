# $NetBSD: Makefile,v 1.8 2008/03/04 16:38:12 jlam Exp $

DISTNAME=	minischeme
PKGNAME=	minischeme-0.85
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/scheme-repository/imp/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Very tiny scheme interpreter

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin

post-extract:
	${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/miniscm ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/minischeme
	for i in init.scm nextleaf.scm tools.scm; do \
		${INSTALL_DATA} ${WRKSRC}/$$i \
			${DESTDIR}${PREFIX}/share/minischeme; \
	done

.include "../../mk/bsd.pkg.mk"
