# $NetBSD: Makefile,v 1.1.1.1 2000/11/02 11:59:07 itojun Exp $

DISTNAME=	umb-scheme-2.12
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/scheme-repository/imp/umb/

MAINTAINER=	packages@netbsd.org

WRKSRC=		${WRKDIR}/scheme-2.12
ALL_TARGET=	default

post-patch:
	${SED} -e "s,@PREFIX@,${PREFIX}," <${FILESDIR}/path.h >${WRKSRC}/path.h
	${MV} ${WRKSRC}/scheme.1 ${WRKSRC}/scheme.1.dist
	${SED} -e "s,@PREFIX@,${PREFIX}," <${WRKSRC}/scheme.1.dist \
	    >${WRKSRC}/scheme.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scheme ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib/umb-scheme
	${INSTALL_DATA} ${WRKSRC}/prelude.scheme ${PREFIX}/lib/umb-scheme
	${INSTALL_MAN} ${WRKSRC}/scheme.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
