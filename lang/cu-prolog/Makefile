# $NetBSD: Makefile,v 1.16 2008/03/04 16:38:11 jlam Exp $

DISTNAME=	cu-prolog-3.94
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.icot.or.jp/ifs/kbms-clp/unix/cuprolog/
DISTFILES=	cupsrc.tar.gz cupdoc.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Experimental constraint logic programming language

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/src
DIST_SUBDIR=	${DISTNAME}
MAKE_FILE=	makefile
BUILD_TARGET=	cup

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cup3 ${DESTDIR}${PREFIX}/bin/cuprolog
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/cu-prolog
	cd ${WRKDIR} && ${INSTALL_DATA} README* COPYRIGHT* CHANGES	\
		doc/*.dvi doc/*.doc ${DESTDIR}${PREFIX}/share/doc/cu-prolog
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/cu-prolog
	${INSTALL_DATA} ${WRKDIR}/sample/*				\
		${DESTDIR}${PREFIX}/share/examples/cu-prolog

.include "../../mk/bsd.pkg.mk"
