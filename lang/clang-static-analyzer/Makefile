# $NetBSD: Makefile,v 1.1 2015/11/06 13:50:05 wiz Exp $

PKGNAME=		${DISTNAME:S/clang/clang-static-analyzer/}

DEPENDS+=		clang>=${PKGVERSION_NOREV}:../../lang/clang

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/llvm/static-analyzer
INSTALLATION_DIRS+=	share/llvm/static-analyzer/Resources

USE_TOOLS+=	perl:run
REPLACE_PERL+=	tools/clang/tools/scan-build/c++-analyzer
REPLACE_PERL+=	tools/clang/tools/scan-build/ccc-analyzer
REPLACE_PERL+=	tools/clang/tools/scan-build/scan-build

REPLACE_PYTHON+=		tools/clang/tools/scan-view/scan-view
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 3.5
.include "../../lang/python/application.mk"

do-build:
	${ECHO} '#!/bin/sh' > ${WRKSRC}/scan-view
	${ECHO} "${PREFIX}/share/llvm/static-analyzer/scan-view "'"$$@"' >> ${WRKSRC}/scan-view

do-install:
	cd ${WRKSRC}/tools/clang/tools/scan-build && \
		${INSTALL_SCRIPT} scan-build ${DESTDIR}${PREFIX}/bin; \
		${INSTALL_SCRIPT} c++-analyzer ccc-analyzer ${DESTDIR}${PREFIX}/libexec; \
		${INSTALL_DATA} scan-build.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1; \
		${INSTALL_DATA} scanview.css sorttable.js ${DESTDIR}${PREFIX}/share/llvm/static-analyzer
	cd ${WRKSRC}/tools/clang/tools/scan-view && \
		${INSTALL_DATA} Resources/* ${DESTDIR}${PREFIX}/share/llvm/static-analyzer/Resources; \
		${INSTALL_SCRIPT} scan-view ${DESTDIR}${PREFIX}/share/llvm/static-analyzer; \
		${INSTALL_DATA} *.py ${DESTDIR}${PREFIX}/share/llvm/static-analyzer
	${INSTALL_SCRIPT} ${WRKSRC}/scan-view ${DESTDIR}${PREFIX}/bin

.include "../../lang/clang/Makefile.common"
