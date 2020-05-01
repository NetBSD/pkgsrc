# $NetBSD: bootstrap.mk,v 1.3 2020/05/01 16:55:28 tnn Exp $

.if !defined(GOROOT_BOOTSTRAP) || !exists(${GOROOT_BOOTSTRAP}/bin/go)
BUILD_DEPENDS+=		go14-1.4*:../../lang/go14
GOROOT_BOOTSTRAP=	${PREFIX}/go14

.  if ${MACHINE_ARCH} == "aarch64"
PKG_FAIL_REASON+=	"${MACHINE_ARCH} bootstrap toolchain missing!"
PKG_FAIL_REASON+=	"Please read ${PKGSRCDIR}/lang/go/bootstrap.mk"
# For now you must manually set GOROOT_BOOTSTRAP in mk.conf.
# I've uploaded a prebuilt NetBSD/evbarm-aarch64 pkgsrc package here:
# https://ftp.netbsd.org/pub/pkgsrc/misc/tnn/golang-aarch64/
#
# Also this kernel patch is needed:
# https://netbsd.org/~tnn/uc_setstack.diff.txt
#
.  endif

.endif
