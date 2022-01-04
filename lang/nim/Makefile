# $NetBSD: Makefile,v 1.24 2022/01/04 12:49:08 ryoon Exp $

DISTNAME=	nim-1.6.2
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

# nim doesn't honor the environment variable LDFLAGS. In order to
# support PKGSRC_USE_RELRO, we need to translate the flags to compiler
# options.
NIM_FLAGS=	${LDFLAGS:S/^/--passL:/}
do-build:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} sh ./build.sh
	printf '#! %s\nexec %s _=%s/nim/bin/nim %s/nim/bin/nim "$$@"\n' \
		"${SH}" "${SETENV}" "${PREFIX}" "${PREFIX}" \
		> ${WRKSRC}/nim-wrapper.sh
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./bin/nim c --skipUserCfg --skipParentCfg --parallelBuild:${_MAKE_JOBS_N} koch
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./koch boot --parallelBuild:${_MAKE_JOBS_N} -d:release ${NIM_FLAGS}
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./koch --stable tools --parallelBuild:${_MAKE_JOBS_N} ${NIM_FLAGS}

do-install:
	cd ${WRKSRC} && sh ./install.sh ${DESTDIR}${PREFIX}
	${INSTALL_SCRIPT} ${WRKSRC}/nim-wrapper.sh ${DESTDIR}${PREFIX}/bin/nim
	${INSTALL} ${WRKSRC}/bin/nimble ${DESTDIR}${PREFIX}/bin/nimble
	${INSTALL} ${WRKSRC}/bin/nimgrep ${DESTDIR}${PREFIX}/bin/nimgrep
	${INSTALL} ${WRKSRC}/bin/nimpretty ${DESTDIR}${PREFIX}/bin/nimpretty
	${INSTALL} ${WRKSRC}/bin/nimsuggest ${DESTDIR}${PREFIX}/bin/nimsuggest
	${INSTALL} ${WRKSRC}/bin/testament ${DESTDIR}${PREFIX}/bin/testament
	${INSTALL} ${WRKSRC}/bin/nim-gdb ${DESTDIR}${PREFIX}/bin/nim-gdb
	${INSTALL} ${WRKSRC}/bin/nim-gdb.bash ${DESTDIR}${PREFIX}/bin/nim-gdb.bash
	${INSTALL} ${WRKSRC}/bin/nim-gdb ${DESTDIR}${PREFIX}/bin/nim_dbg

do-test:
	cd ${WRKSRC} && ./bin/nim compile koch.nim
	cd ${WRKSRC} && LD_LIBRARY_PATH=${PREFIX}/lib ./koch test --parallelBuild:${_MAKE_JOBS_N}

.include "../../mk/bsd.pkg.mk"
