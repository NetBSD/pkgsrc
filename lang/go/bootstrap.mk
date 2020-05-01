# $NetBSD: bootstrap.mk,v 1.2 2020/05/01 14:39:37 tnn Exp $

.if !defined(GOROOT_BOOTSTRAP) || !exists(${GOROOT_BOOTSTRAP}/bin/go)
BUILD_DEPENDS+=		go14-1.4*:../../lang/go14
GOROOT_BOOTSTRAP=	${PREFIX}/go14
.endif
