# $NetBSD: Makefile,v 1.21 2006/09/09 02:43:10 obache Exp $

DISTNAME=	tochnog-20010429
CATEGORIES=	math
MASTER_SITES=	ftp://tochnog.sourceforge.net/pub/tochnog/
DISTFILES=	tn.tar.gz tnu.ps.gz tnp.ps.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tochnog.sourceforge.net/
COMMENT=	Finite Element Analysis Program

WRKSRC=		${WRKDIR}/tochnog/src
DIST_SUBDIR=	${DISTNAME}
EXTRACT_ONLY=	tn.tar.gz
MAKE_FILE=	makefile
BUILD_TARGET=	netbsd

MAKE_ENV+=	MACHINE_ARCH=${MACHINE_ARCH:Q}

USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin share/doc/tochnog share/tochnog/tools share/tochnog/test

post-patch:
	@${RM} -f ${WRKDIR}/tochnog/test/*.orig ${WRKDIR}/tochnog/tools/*.bat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tochnog ${PREFIX}/bin
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/tnu.ps.gz \
	${PREFIX}/share/doc/tochnog
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/tnp.ps.gz \
	${PREFIX}/share/doc/tochnog
	${INSTALL_DATA} ${WRKDIR}/tochnog/test/* ${PREFIX}/share/tochnog/test/
	${INSTALL_DATA} ${WRKDIR}/tochnog/tools/* ${PREFIX}/share/tochnog/tools/

.include "../../mk/bsd.pkg.mk"
