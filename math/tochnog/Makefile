# $NetBSD: Makefile,v 1.26 2020/03/20 11:58:01 nia Exp $

DISTNAME=	tochnog-20010429
CATEGORIES=	math
MASTER_SITES=	http://sourceforge.net/projects/tochnog/files/tochnog/
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

INSTALLATION_DIRS=	bin share/doc/tochnog share/tochnog/tools \
			share/tochnog/test

post-patch:
	@${RM} -f ${WRKDIR}/tochnog/test/*.orig ${WRKDIR}/tochnog/tools/*.bat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tochnog ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/tnu.ps.gz \
		${DESTDIR}${PREFIX}/share/doc/tochnog
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/tnp.ps.gz \
		${DESTDIR}${PREFIX}/share/doc/tochnog
	${INSTALL_DATA} ${WRKDIR}/tochnog/test/* \
		${DESTDIR}${PREFIX}/share/tochnog/test/
	${INSTALL_DATA} ${WRKDIR}/tochnog/tools/* \
		${DESTDIR}${PREFIX}/share/tochnog/tools/

.include "../../mk/bsd.pkg.mk"
