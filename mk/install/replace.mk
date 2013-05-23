# $NetBSD: replace.mk,v 1.15 2013/05/23 13:18:56 obache Exp $
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
# Private targets that must be defined by the package system format:
#
# _pkgformat-replace:
#	Updates a package in-place on the system (USE_DESTDIR=no).
#
# _pkgformat-destdir-replace:
#	Updates a package in-place on the system (USE_DESTDIR=yes).
#
# _pkgformat-undo-replace:
#	Undoes a previous "make _pkgformat-replace".

# _pkgformat-destdir-undo-replace:
#	Undoes a previous "make _pkgformat-destdir-replace".

.if ${_USE_DESTDIR} == "no"
_REPLACE_TARGETS+=	${_PKGSRC_BUILD_TARGETS}
.else
_REPLACE_TARGETS+=	stage-package-create
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
su-replace: .PHONY _pkgformat-replace
.else
su-replace: .PHONY _pkgformat-destdir-replace
.endif
MAKEFLAGS.su-replace=	_UPDATE_RUNNING=yes
MAKEFLAGS.su-replace+=	PKGNAME_REQD=${PKGNAME_REQD:Q}

#
# undo-replace
#

undo-replace: .PHONY undo-replace-message su-target

undo-replace-message: .PHONY
	@${PHASE_MSG} "Undoing replacement for ${PKGNAME}"
	@${WARNING_MSG} "experimental target - DATA LOSS MAY OCCUR."

.if ${_USE_DESTDIR} == "no"
su-undo-replace: .PHONY _pkgformat-undo-replace
.else
su-undo-replace: .PHONY _pkgformat-destdir-undo-replace
.endif
MAKEFLAGS.su-undo-replace=	_UPDATE_RUNNING=yes
