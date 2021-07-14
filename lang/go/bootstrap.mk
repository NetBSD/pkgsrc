# $NetBSD: bootstrap.mk,v 1.6 2021/07/14 10:18:28 jperkin Exp $

.if !defined(GOROOT_BOOTSTRAP) || !exists(${GOROOT_BOOTSTRAP}/bin/go)
.  if ${MACHINE_ARCH} == "aarch64"
BUILD_DEPENDS+=		go-bin-[0-9]*:../../lang/go-bin
GOROOT_BOOTSTRAP=	${PREFIX}/go-bin
.    if ${OPSYS} == "Darwin"
pre-build: remove-codesign
remove-codesign:
	@for f in ${PREFIX}/go-bin/bin/* ${PREFIX}/go-bin/pkg/tool/darwin_arm64/*; do \
		/usr/bin/codesign --remove-signature $$f; \
	done
.    endif
.  else
BUILD_DEPENDS+=		go14-1.4*:../../lang/go14
GOROOT_BOOTSTRAP=	${PREFIX}/go14
.  endif
.endif
