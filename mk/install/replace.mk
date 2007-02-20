# $NetBSD: replace.mk,v 1.8 2007/02/20 11:17:03 rillig Exp $
#
# Public targets:
#
# replace:
#	Updates a package in-place on the system.
#	It will acquire elevated privileges just-in-time.
#
# undo-replace:
#	Undoes the effects of a previous "make replace".
#	It will acquire elevated privileges just-in-time.
#
#
# Private targets that must be defined by the package system flavor:
#
# replace-pkg:
#	Updates a package in-place on the system.
#
# undo-replace-pkg:
#	Undoes a previous "make replace-pkg".

_REPLACE_TARGETS+=	${_PKGSRC_BUILD_TARGETS}
_REPLACE_TARGETS+=	replace-message
_REPLACE_TARGETS+=	unprivileged-install-hook

#
# replace
#

.PHONY: replace su-replace
.if defined(_PKGSRC_BARRIER)
replace: ${_REPLACE_TARGETS} su-target
.else
replace: barrier
.endif

replace-message:
	@${PHASE_MSG} "Replacing for ${PKGNAME}"
        @${WARNING_MSG} "experimental target - DATA LOSS MAY OCCUR."

su-replace: replace-pkg
MAKEFLAGS.su-replace=	_UPDATE_RUNNING=yes

#
# undo-replace
#

.PHONY: undo-replace su-undo-replace
undo-replace: undo-replace-message su-target

undo-replace-message:
	@${PHASE_MSG} "Undoing replacement for ${PKGNAME}"
        @${WARNING_MSG} "experimental target - DATA LOSS MAY OCCUR."

su-undo-replace: undo-replace-pkg
MAKEFLAGS.su-undo-replace=	_UPDATE_RUNNING=yes
