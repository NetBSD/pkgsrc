# $NetBSD: Makefile,v 1.16 2020/06/21 07:43:29 ryoon Exp $

DISTNAME=	nim-1.2.2
CATEGORIES=	lang
MASTER_SITES=	http://nim-lang.org/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://nim-lang.org/
COMMENT=	The Nim programming language
LICENSE=	mit

DEPENDS+=	coreutils-[0-9]*:../../sysutils/coreutils

USE_TOOLS+=	bash
REPLACE_BASH+=	bin/nim-gdb

INSTALLATION_DIRS=	bin

post-patch:
	cd ${WRKSRC}/bin && ${LN} -sf nim-gdb nim-gdb.bash

do-build:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} sh ./build.sh
	printf '#! %s\nexec %s _=%s/nim/bin/nim %s/nim/bin/nim "$$@"\n' \
		"${SH}" "${SETENV}" "${PREFIX}" "${PREFIX}" \
		> ${WRKSRC}/nim-wrapper.sh
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./bin/nim c --skipUserCfg --skipParentCfg koch
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./koch boot -d:release --skipUserCfg --skipParentCfg
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./koch tools --skipUserCfg --skipParentCfg

do-install:
	cd ${WRKSRC} && sh ./install.sh ${DESTDIR}${PREFIX}
	${INSTALL_SCRIPT} ${WRKSRC}/nim-wrapper.sh ${DESTDIR}${PREFIX}/bin/nim
	${INSTALL} ${WRKSRC}/bin/nimble ${DESTDIR}${PREFIX}/bin/nimble
	${INSTALL} ${WRKSRC}/bin/nimfind ${DESTDIR}${PREFIX}/bin/nimfind
	${INSTALL} ${WRKSRC}/bin/nimgrep ${DESTDIR}${PREFIX}/bin/nimgrep
	${INSTALL} ${WRKSRC}/bin/nimpretty ${DESTDIR}${PREFIX}/bin/nimpretty
	${INSTALL} ${WRKSRC}/bin/nimsuggest ${DESTDIR}${PREFIX}/bin/nimsuggest
	${INSTALL} ${WRKSRC}/bin/testament ${DESTDIR}${PREFIX}/bin/testament

do-test:
	cd ${WRKSRC} && ./bin/nim compile koch.nim
	cd ${WRKSRC} && LD_LIBRARY_PATH=${PREFIX}/lib ./koch tests

.include "../../mk/bsd.pkg.mk"
