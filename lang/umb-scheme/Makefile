# $NetBSD: Makefile,v 1.3 2001/02/25 04:17:57 hubertf Exp $

DISTNAME=	umb-scheme-2.12
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/scheme-repository/imp/umb/

MAINTAINER=	packages@netbsd.org
COMMENT=	UMB scheme interpreter

WRKSRC=		${WRKDIR}/scheme-2.12
ALL_TARGET=	default

post-patch:
	${SED} -e "s,@PREFIX@,${PREFIX}," <${FILESDIR}/path.h >${WRKSRC}/path.h
	${MV} ${WRKSRC}/scheme.1 ${WRKSRC}/scheme.1.dist
	${SED} -e "s,@PREFIX@,${PREFIX}," <${WRKSRC}/scheme.1.dist \
	    >${WRKSRC}/scheme.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scheme ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/lib/umb-scheme
	${INSTALL_DATA} ${WRKSRC}/prelude.scheme ${PREFIX}/lib/umb-scheme
	${INSTALL_MAN} ${WRKSRC}/scheme.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
