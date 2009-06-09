# $NetBSD: replace.mk,v 1.11 2009/06/09 08:40:28 joerg Exp $
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
# _flavor-replace:
#	Updates a package in-place on the system (USE_DESTDIR=no).
#
# _flavor-destdir-replace:
#	Updates a package in-place on the system (USE_DESTDIR=yes).
#
# _flavor-undo-replace:
#	Undoes a previous "make _flavor-replace".

.if ${_USE_DESTDIR} == "no"
_REPLACE_TARGETS+=	${_PKGSRC_BUILD_TARGETS}
.else
_REPLACE_TARGETS+=	package
.endif
_REPLACE_TARGETS+=	replace-message
_REPLACE_TARGETS+=	unprivileged-install-hook

#
# replace
#

.PHONY: replace
.if defined(_PKGSRC_BARRIER)
replace: ${_REPLACE_TARGETS} su-target
.else
replace: barrier
.endif

replace-message: .PHONY
	@${PHASE_MSG} "Replacing for ${PKGNAME}"
	@${WARNING_MSG} "experimental target - DATA LOSS MAY OCCUR."

.if ${_USE_DESTDIR} == "no"
su-replace: .PHONY _flavor-replace
.else
su-replace: .PHONY _flavor-destdir-replace
.endif
MAKEFLAGS.su-replace=	_UPDATE_RUNNING=yes

#
# undo-replace
#

undo-replace: .PHONY undo-replace-message su-target

undo-replace-message: .PHONY
	@${PHASE_MSG} "Undoing replacement for ${PKGNAME}"
	@${WARNING_MSG} "experimental target - DATA LOSS MAY OCCUR."

su-undo-replace: .PHONY _flavor-undo-replace
MAKEFLAGS.su-undo-replace=	_UPDATE_RUNNING=yes
