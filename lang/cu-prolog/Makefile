# $NetBSD: Makefile,v 1.9 2003/07/17 21:44:09 grant Exp $
# FreeBSD Id: Makefile,v 1.2 2000/04/12 06:18:03 obrien Exp

DISTNAME=	cu-prolog-3.94
WRKSRC=		${WRKDIR}/src
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.icot.or.jp/ifs/kbms-clp/unix/cuprolog/
DISTFILES=	cupsrc.tar.gz cupdoc.tar.gz

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Experimental constraint logic programming language

DIST_SUBDIR=	${DISTNAME}
MAKEFILE=	makefile
ALL_TARGET=	cup

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cup3 ${PREFIX}/bin/cuprolog
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cu-prolog
	cd ${WRKDIR} && ${INSTALL_DATA} README* COPYRIGHT* CHANGES	\
		doc/*.dvi doc/*.doc ${PREFIX}/share/doc/cu-prolog
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cu-prolog
	${INSTALL_DATA} ${WRKDIR}/sample/* ${PREFIX}/share/examples/cu-prolog

.include "../../mk/bsd.pkg.mk"
