# $NetBSD: Makefile,v 1.2 2017/02/05 01:27:30 kamil Exp $

DISTNAME=	nim-0.16.0
CATEGORIES=	lang
MASTER_SITES=	http://nim-lang.org/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	The Nim programming language
LICENSE=	mit

AUTO_MKDIRS=	yes

do-build:
	cd ${WRKSRC} && sh ./build.sh
	printf '#! %s\nexec %s _=%s/nim/bin/nim %s/nim/bin/nim "$$@"\n' \
		"${SH}" "${SETENV}" "${PREFIX}" "${PREFIX}" \
		> ${WRKSRC}/nim-wrapper.sh

do-install:
	cd ${WRKSRC} && sh ./install.sh ${DESTDIR}${PREFIX}
	${INSTALL_SCRIPT} ${WRKSRC}/nim-wrapper.sh ${DESTDIR}${PREFIX}/bin/nim

do-test:
	cd ${WRKSRC} && ./bin/nim compile koch.nim
	cd ${WRKSRC} && LD_LIBRARY_PATH=$PREFIX/lib ./koch tests

.include "../../mk/bsd.pkg.mk"
