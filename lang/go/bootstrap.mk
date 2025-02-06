# $NetBSD: bootstrap.mk,v 1.15 2025/02/06 00:24:36 riastradh Exp $

.if !defined(GOROOT_BOOTSTRAP) || !exists(${GOROOT_BOOTSTRAP}/bin/go)
.  if (${MACHINE_ARCH} == "aarch64" && ${USE_CROSS_COMPILE:tl} == "no") || \
    (${OPSYS} == "Darwin" && ${OPSYS_VERSION} >= 120000) || \
    (${OPSYS} == "FreeBSD" && ${OPSYS_VERSION} >= 140000) || \
    (${OPSYS} == "SunOS" && ${OS_VARIANT} != "Solaris")
TOOL_DEPENDS+=		go-bin-[0-9]*:../../lang/go-bin
GOROOT_BOOTSTRAP=	${TOOLBASE}/go-bin
.  elif defined(GO_BOOTSTRAP_REQD)
TOOL_DEPENDS+=		go${GO_BOOTSTRAP_REQD}-[0-9]*:../../lang/go${GO_BOOTSTRAP_REQD}
GOROOT_BOOTSTRAP=	${TOOLBASE}/go${GO_BOOTSTRAP_REQD}
.  else
TOOL_DEPENDS+=		go14-1.4*:../../lang/go14
GOROOT_BOOTSTRAP=	${TOOLBASE}/go14
.  endif
.endif
