# $NetBSD: Makefile,v 1.10 2005/06/16 06:58:01 jlam Exp $

DISTNAME=		umb-scheme-3.2
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.cs.umb.edu/pub/scheme/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		UMB Scheme interpreter

WRKSRC=			${WRKDIR}/scheme-3.2
BUILD_TARGET=		default
INSTALLATION_DIRS=	bin man/man1

pre-patch:
	${MV} ${WRKSRC}/scheme.1 ${WRKSRC}/scheme.1.dist
	${SED} -e 's:\$$::g' ${WRKSRC}/scheme.1.dist > ${WRKSRC}/scheme.1.tmp

post-patch:
	${SED} -e "s,@PREFIX@,${PREFIX}," ${FILESDIR}/path.h >${WRKSRC}/path.h
	${SED} -e "s,@PREFIX@,${PREFIX}," ${WRKSRC}/scheme.1.tmp \
		>${WRKSRC}/scheme.1
	${MV} ${WRKSRC}/prelude.scheme ${WRKSRC}/prelude.scheme.dist
	${SED} -e "s,@PREFIX@,${PREFIX}," ${WRKSRC}/prelude.scheme.dist	\
		>${WRKSRC}/prelude.scheme
	${MV} ${WRKSRC}/SLIB-for-umb-scheme.init \
		${WRKSRC}/SLIB-for-umb-scheme.init.dist
	${SED} -e "s,@PREFIX@,${PREFIX}," \
		${WRKSRC}/SLIB-for-umb-scheme.init.dist \
		>${WRKSRC}/SLIB-for-umb-scheme.init

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/umb-scheme ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/umb-scheme
	${INSTALL_DATA} ${WRKSRC}/prelude.scheme ${PREFIX}/share/umb-scheme
	${INSTALL_DATA} ${WRKSRC}/SLIB-for-umb-scheme.init \
		${PREFIX}/share/umb-scheme
	${INSTALL_MAN} ${WRKSRC}/scheme.1 ${PREFIX}/man/man1/umb-scheme.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/umb-scheme/slib
	${INSTALL_DATA} ${WRKSRC}/slib/*.scm ${PREFIX}/share/umb-scheme/slib

.include "../../mk/bsd.pkg.mk"
