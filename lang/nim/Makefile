# $NetBSD: Makefile,v 1.17 2020/08/09 22:11:29 nikita Exp $

DISTNAME=	nim-1.2.6
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
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./bin/nim c --skipUserCfg --skipParentCfg --parallelBuild:${_MAKE_JOBS_N} koch
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./koch boot --parallelBuild:${_MAKE_JOBS_N} -d:release --skipUserCfg --skipParentCfg
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./koch --stable tools --parallelBuild:${_MAKE_JOBS_N} --skipUserCfg --skipParentCfg

do-install:
	cd ${WRKSRC} && sh ./install.sh ${DESTDIR}${PREFIX}
	${INSTALL_SCRIPT} ${WRKSRC}/nim-wrapper.sh ${DESTDIR}${PREFIX}/bin/nim
	${INSTALL} ${WRKSRC}/bin/nimble ${DESTDIR}${PREFIX}/bin/nimble
	${INSTALL} ${WRKSRC}/bin/nimfind ${DESTDIR}${PREFIX}/bin/nimfind
	${INSTALL} ${WRKSRC}/bin/nimgrep ${DESTDIR}${PREFIX}/bin/nimgrep
	${INSTALL} ${WRKSRC}/bin/nimpretty ${DESTDIR}${PREFIX}/bin/nimpretty
	${INSTALL} ${WRKSRC}/bin/nimsuggest ${DESTDIR}${PREFIX}/bin/nimsuggest
	${INSTALL} ${WRKSRC}/bin/testament ${DESTDIR}${PREFIX}/bin/testament
	${INSTALL} ${WRKSRC}/bin/nim-gdb ${DESTDIR}${PREFIX}/bin/nim-gdb
	${INSTALL} ${WRKSRC}/bin/nim-gdb.bash ${DESTDIR}${PREFIX}/bin/nim-gdb.bash

do-test:
	cd ${WRKSRC} && ./bin/nim compile koch.nim
	cd ${WRKSRC} && LD_LIBRARY_PATH=${PREFIX}/lib ./koch test --parallelBuild:${_MAKE_JOBS_N}

.include "../../mk/bsd.pkg.mk"
