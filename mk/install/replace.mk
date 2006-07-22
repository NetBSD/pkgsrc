# $NetBSD: replace.mk,v 1.7 2006/07/22 16:31:35 jlam Exp $

######################################################################
### replace (PUBLIC)
######################################################################
### replace is a public target to update a package in-place on the
### system.  It will acquire elevated privileges just-in-time.
###
_REPLACE_TARGETS+=	${_PKGSRC_BUILD_TARGETS}
_REPLACE_TARGETS+=	replace-message
_REPLACE_TARGETS+=	unprivileged-install-hook

.PHONY: replace su-replace
.if !target(replace)
.  if defined(_PKGSRC_BARRIER)
replace: ${_REPLACE_TARGETS} su-target
.  else
replace: barrier
.  endif
.endif

replace-message:
	@${PHASE_MSG} "Replacing for ${PKGNAME}"
        @${WARNING_MSG} "experimental target - DATA LOSS MAY OCCUR."

su-replace: replace-pkg
MAKEFLAGS.su-replace=	_UPDATE_RUNNING=yes

######################################################################
### undo-replace (PUBLIC)
######################################################################
### undo-replace is a public target to undo the effects of the
### "replace" target.  It will acquire elevated privileges just-in-time.
###
.PHONY: undo-replace su-undo-replace
.if !target(undo-replace)
undo-replace: undo-replace-message su-target
.endif

undo-replace-message:
	@${PHASE_MSG} "Undoing replacement for ${PKGNAME}"
        @${WARNING_MSG} "experimental target - DATA LOSS MAY OCCUR."

su-undo-replace: undo-replace-pkg
MAKEFLAGS.su-undo-replace=	_UPDATE_RUNNING=yes

######################################################################
### replace-pkg (PRIVATE, override)
######################################################################
### replace-pkg updates a package in-place on the system.  This should
### be overridden per package system flavor.
###
.if !target(replace-pkg)
replace-pkg:
	@${DO_NADA}
.endif

######################################################################
### undo-replace-pkg (PRIVATE, override)
######################################################################
### undo-replace-pkg undoes a "make replace".  This should be overridden
### per package system flavor.
###
.if !target(undo-replace-pkg)
undo-replace-pkg:
	@${DO_NADA}
.endif
