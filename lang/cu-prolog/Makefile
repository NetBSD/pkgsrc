# $NetBSD: Makefile,v 1.3 2001/03/01 19:06:04 jtb Exp $
# FreeBSD Id: Makefile,v 1.2 2000/04/12 06:18:03 obrien Exp

DISTNAME=	cu-prolog-3.94
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.icot.or.jp/ifs/kbms-clp/unix/cuprolog/
DISTFILES=	cupsrc.tar.gz cupdoc.tar.gz

MAINTAINER=	jtb@netbsd.org
COMMENT=	Experimental constraint logic programming language

DIST_SUBDIR=	${DISTNAME}
NO_WRKSUBDIR=	#defined
WRKSRC=		${WRKDIR}/src
MAKEFILE=	makefile
ALL_TARGET=	cup

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cup3 ${PREFIX}/bin/cuprolog
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cu-prolog
	@for f in ${WRKDIR}/README* ${WRKDIR}/COPYRIGHT*		\
	${WRKDIR}/CHANGES ${WRKDIR}/doc/*.dvi ${WRKDIR}/doc/*.doc; do	\
	i="${INSTALL_DATA} $$f ${PREFIX}/share/doc/cu-prolog/";		\
	${ECHO} $$i; $$i;						\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cu-prolog
	@for f in ${WRKDIR}/sample/*; do				\
	i="${INSTALL_DATA} $$f ${PREFIX}/share/examples/cu-prolog/";	\
	${ECHO} $$i; $$i;						\
	done

.include "../../mk/bsd.pkg.mk"
