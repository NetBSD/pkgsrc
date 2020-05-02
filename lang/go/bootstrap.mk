# $NetBSD: bootstrap.mk,v 1.4 2020/05/02 20:12:34 tnn Exp $

.if !defined(GOROOT_BOOTSTRAP) || !exists(${GOROOT_BOOTSTRAP}/bin/go)
.  if !empty(MACHINE_PLATFORM:MNetBSD-*-aarch64) ||	\
	!empty(MACHINE_PLATFORM:MLinux-*-aarch64)
BUILD_DEPENDS+=		go-bin-[0-9]*:../../lang/go-bin
GOROOT_BOOTSTRAP=	${PREFIX}/go-bin
.  else
BUILD_DEPENDS+=		go14-1.4*:../../lang/go14
GOROOT_BOOTSTRAP=	${PREFIX}/go14
.  endif
.endif
