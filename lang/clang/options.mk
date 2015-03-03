# $NetBSD: options.mk,v 1.2 2015/03/03 16:27:33 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.clang
PKG_SUPPORTED_OPTIONS=	clang-static-analyzer shlib
PKG_SUGGESTED_OPTIONS=	# clang-static-analyzer disabled since it needs python and perl

.include "../../mk/bsd.options.mk"

PLIST_SRC=		${PLIST_SRC_DFLT}

# XXX should be spun off to a libLLVM package when we have a use case for it
.if !empty(PKG_OPTIONS:Mshlib)
PLIST_SRC+=		PLIST.shlib
CONFIGURE_ARGS+=	--enable-shared
MAKE_ENV+=		SHARED_LIBRARY=1
MAKE_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/Release/lib
# fixup shared library dependencies in a less intrusive way than patching
BUILDLINK_TRANSFORM+=	l:clangTooling:clangToolingCore:clangASTMatchers:clangTooling
BUILDLINK_TRANSFORM+=	l:LLVMMipsDesc:LLVMMipsAsmPrinter:LLVMMipsDesc
BUILDLINK_TRANSFORM+=	l:LLVMARMAsmParser:LLVMARMInfo:LLVMARMAsmParser
BUILDLINK_TRANSFORM+=	l:clangARCMigrate:clangStaticAnalyzerCore:clangStaticAnalyzerCheckers:clangARCMigrate
BUILDLINK_TRANSFORM+=	l:clangStaticAnalyzerCheckers:clangStaticAnalyzerCore:clangStaticAnalyzerCheckers
BUILDLINK_TRANSFORM+=	l:clangFrontendTool:clangStaticAnalyzerFrontend:clangFrontendTool
.endif

.if !empty(PKG_OPTIONS:Mclang-static-analyzer)
PLIST_SRC+=		PLIST.static-analyzer

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

post-build:
	${ECHO} '#!/bin/sh' > ${WRKSRC}/scan-view
	${ECHO} "${PREFIX}/share/llvm/static-analyzer/scan-view "'"$$@"' >> ${WRKSRC}/scan-view
post-install:
	cd ${WRKSRC}/tools/clang/tools/scan-build && \
		${INSTALL_SCRIPT} scan-build ${DESTDIR}${PREFIX}/bin; \
		${INSTALL_SCRIPT} c++-analyzer ccc-analyzer ${DESTDIR}${PREFIX}/libexec; \
		${INSTALL_DATA} scan-build.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1; \
		${INSTALL_DATA} scanview.css sorttable.js ${DESTDIR}${PREFIX}/share/llvm/static-analyzer
	cd ${WRKSRC}/tools/clang/tools/scan-view && \
		${INSTALL_DATA} Resources/* ${DESTDIR}${PREFIX}/share/llvm/static-analyzer/Resources; \
		${INSTALL_SCRIPT} scan-view *.py ${DESTDIR}${PREFIX}/share/llvm/static-analyzer
	${INSTALL_SCRIPT} ${WRKSRC}/scan-view ${DESTDIR}${PREFIX}/bin
.endif
