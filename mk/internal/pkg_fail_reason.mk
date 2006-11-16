# $NetBSD: pkg_fail_reason.mk,v 1.2 2006/11/16 09:38:53 rillig Exp $
#

# This file prints the error that are collected when the Makefiles are
# loaded.
#

PKG_FAIL_REASON?=	# none
PKG_SKIP_REASON?=	# none

.PHONY: _check-pkg-fail-reason
_check-pkg-fail-reason: .USEBEFORE
.if defined(SKIP_SILENT)
	@${DO_NADA}
.else
.  if !empty(PKG_FAIL_REASON:M*)
	@for str in ${PKG_FAIL_REASON}; do				\
		${ERROR_MSG} "$$str";					\
	done
.  endif
.  if !empty(PKG_SKIP_REASON:M*)
	@for str in "Skipping ${PKGNAME}:" ${PKG_SKIP_REASON}; do	\
		${WARNING_MSG} "$$str";					\
	done
.  endif
.endif
.if !empty(PKG_FAIL_REASON:M*)
	@${FALSE}
.endif

# All the "public" targets should be listed here.
#
.if !defined(NO_SKIP)
.  if !empty(PKG_FAIL_REASON) || !empty(PKG_SKIP_REASON)
# FIXME: check-vulnerable is only used here because it is depended
# upon by each of the "main" pkgsrc targets. Probably its name should be
# generalized, and both check-vulnerable and _check-pkg-fail-reason should
# depend on the generalized target.
check-vulnerable: _check-pkg-fail-reason
.  endif
.endif # !NO_SKIP
