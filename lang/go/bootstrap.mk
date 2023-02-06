# $NetBSD: bootstrap.mk,v 1.11 2023/02/06 20:53:02 ryoon Exp $

.if !defined(GOROOT_BOOTSTRAP) || !exists(${GOROOT_BOOTSTRAP}/bin/go)
.  if ${MACHINE_ARCH} == "aarch64" || \
    (${OPSYS} == "Darwin" && ${OPSYS_VERSION} >= 120000) || \
    (${OPSYS} == "SunOS" && ${OS_VARIANT} != "Solaris")
BUILD_DEPENDS+=		go-bin-[0-9]*:../../lang/go-bin
GOROOT_BOOTSTRAP=	${PREFIX}/go-bin
.  elif defined(GO_BOOTSTRAP_REQD)
BUILD_DEPENDS+=		go${GO_BOOTSTRAP_REQD}-[0-9]*:../../lang/go${GO_BOOTSTRAP_REQD}
GOROOT_BOOTSTRAP=	${PREFIX}/go${GO_BOOTSTRAP_REQD}
.  else
BUILD_DEPENDS+=		go14-1.4*:../../lang/go14
GOROOT_BOOTSTRAP=	${PREFIX}/go14
.  endif
.endif
