# $NetBSD: bootstrap.mk,v 1.1 2020/05/01 14:09:14 tnn Exp $

BUILD_DEPENDS+=		go14-1.4*:../../lang/go14
GOROOT_BOOTSTRAP=	${PREFIX}/go14
