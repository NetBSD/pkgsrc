# $NetBSD: Makefile,v 1.1.1.1 2001/02/10 04:30:48 jtb Exp $

DISTNAME=	tochnog-20010210
CATEGORIES=	math
MASTER_SITES=	http://tochnog.sourceforge.net/
DISTFILES=	tn.tar.gz tnu.ps.gz tnp.ps.gz

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://tochnog.sourceforge.net

DIST_SUBDIR=	${DISTNAME}
EXTRACT_ONLY=	tn.tar.gz
WRKSRC=		${WRKDIR}/tochnog/src
MAKEFILE=	makefile
ALL_TARGET=	netbsd

post-patch:
	@${RM} -f ${WRKDIR}/test/*.orig ${WRKDIR}/tools/*.bat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tochnog ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tochnog
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/tnu.ps.gz ${PREFIX}/share/doc/tochnog
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/tnp.ps.gz ${PREFIX}/share/doc/tochnog
	${INSTALL_DATA_DIR} ${PREFIX}/share/tochnog/test
	@for f in ${WRKDIR}/tochnog/test/*; do			\
	i="${INSTALL_DATA} $$f ${PREFIX}/share/tochnog/test/";	\
	${ECHO} $$i; $$i;					\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/tochnog/tools
	@for f in ${WRKDIR}/tochnog/tools/*; do			\
	i="${INSTALL_DATA} $$f ${PREFIX}/share/tochnog/tools/";	\
	${ECHO} $$i; $$i;					\
	done

.include "../../mk/bsd.pkg.mk"
