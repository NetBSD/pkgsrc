# $NetBSD: Makefile,v 1.13 2005/06/16 06:58:00 jlam Exp $

DISTNAME=	cu-prolog-3.94
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.icot.or.jp/ifs/kbms-clp/unix/cuprolog/
DISTFILES=	cupsrc.tar.gz cupdoc.tar.gz

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Experimental constraint logic programming language

WRKSRC=		${WRKDIR}/src
DIST_SUBDIR=	${DISTNAME}
MAKEFILE=	makefile
BUILD_TARGET=	cup

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cup3 ${PREFIX}/bin/cuprolog
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cu-prolog
	cd ${WRKDIR} && ${INSTALL_DATA} README* COPYRIGHT* CHANGES	\
		doc/*.dvi doc/*.doc ${PREFIX}/share/doc/cu-prolog
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cu-prolog
	${INSTALL_DATA} ${WRKDIR}/sample/* ${PREFIX}/share/examples/cu-prolog

.include "../../mk/bsd.pkg.mk"
