# $NetBSD: pkg_fail_reason.mk,v 1.1 2006/11/14 13:56:14 rillig Exp $
#

# This file prints the error that are collected when the Makefiles are
# loaded.
#

.if !defined(NO_SKIP)

#
# Now print some error messages that we know we should ignore the pkg
#
.  if defined(PKG_FAIL_REASON) || defined(PKG_SKIP_REASON)
.PHONY: do-check-pkg-fail-or-skip-reason
fetch checksum extract patch configure all build install package \
update depends do-check-pkg-fail-or-skip-reason:
.    if defined(SKIP_SILENT)
	@${DO_NADA}
.    else
.      if defined(PKG_FAIL_REASON) && !empty(PKG_FAIL_REASON:M*)
	@for str in ${PKG_FAIL_REASON}; do				\
		${ERROR_MSG} "$$str";					\
	done
.      endif
.      if defined(PKG_SKIP_REASON) && !empty(PKG_SKIP_REASON:M*)
	@${WARNING_MSG} "Skipping ${PKGNAME}:";				\
	for str in ${PKG_SKIP_REASON}; do				\
		${WARNING_MSG} "$$str";					\
	done
.      endif
.    endif
.    if defined(PKG_FAIL_REASON) && !empty(PKG_FAIL_REASON:M*)
	@${FALSE}
.    endif
.  endif # SKIP
.endif # !NO_SKIP

.PHONY: do-check-pkg-fail-reason
do-check-pkg-fail-reason:
	@${DO_NADA}

# This target should appear as a dependency of every top level target that
# is intended to be called by the user or by a package different from the
# current package.
.if defined(PKG_FAIL_REASON)
do-check-pkg-fail-reason: do-check-pkg-fail-or-skip-reason
.endif
