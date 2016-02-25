# $NetBSD: Makefile,v 1.42 2016/02/25 10:05:48 jperkin Exp $

MAKE_DIRS=		etc/llvm
INSTALLATION_DIRS=	bin lib libexec

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
	for lib in asan_iossim asan_osx ubsan_iossim ubsan_osx; do \
		dydir="lib/clang/${PKGVERSION_NOREV}/lib/darwin"; \
		dylib="libclang_rt.$${lib}_dynamic.dylib"; \
		install_name_tool -id ${PREFIX}/$${dydir}/$${dylib} \
		    ${DESTDIR}${PREFIX}/$${dydir}/$${dylib}; \
	done
	for lib in BugpointPasses LLVMHello libLTO libclang; do \
		install_name_tool -id ${PREFIX}/lib/$${lib}.dylib \
		    ${DESTDIR}${PREFIX}/lib/$${lib}.dylib; \
	done
	install_name_tool -change @rpath/libclang.dylib \
	    ${PREFIX}/lib/libclang.dylib ${DESTDIR}${PREFIX}/bin/c-index-test
.endif

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/clang/Makefile.common"
