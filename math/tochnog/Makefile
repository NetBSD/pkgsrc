# $NetBSD: Makefile,v 1.8 2001/04/29 16:17:50 jtb Exp $

DISTNAME=	tochnog-20010429
CATEGORIES=	math
MASTER_SITES=	ftp://tochnog.sourceforge.net/pub/tochnog/
DISTFILES=	tn.tar.gz tnu.ps.gz tnp.ps.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://tochnog.sourceforge.net
COMMENT=	Finite Element Analysis Program

DIST_SUBDIR=	${DISTNAME}
EXTRACT_ONLY=	tn.tar.gz
WRKSRC=		${WRKDIR}/tochnog/src
MAKEFILE=	makefile
ALL_TARGET=	netbsd

post-patch:
	@${RM} -f ${WRKDIR}/tochnog/test/*.orig ${WRKDIR}/tochnog/tools/*.bat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tochnog ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tochnog
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/tnu.ps.gz \
	${PREFIX}/share/doc/tochnog
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/tnp.ps.gz \
	${PREFIX}/share/doc/tochnog
	${INSTALL_DATA_DIR} ${PREFIX}/share/tochnog/test
	${INSTALL_DATA} ${WRKDIR}/tochnog/test/* ${PREFIX}/share/tochnog/test/
	${INSTALL_DATA_DIR} ${PREFIX}/share/tochnog/tools
	${INSTALL_DATA} ${WRKDIR}/tochnog/tools/* ${PREFIX}/share/tochnog/tools/

.include "../../mk/bsd.pkg.mk"
