# $NetBSD: developer.mk,v 1.6 2007/04/01 21:14:27 wiz Exp $
#
# Public targets for developers:
#
# changes-entry:
#	Appends a correctly-formatted entry to the pkgsrc CHANGES file.
#
#	Command-line variables:
#
#	CTYPE
#		The type of entry to add. Must be one of "Added",
#		"Updated", "Renamed", "Moved", or "Removed".
#		The default is "Updated".
#
#	TO
#		When a package is renamed, this is the new name of the
#		package.
#
#	NETBSD_LOGIN_NAME
#		The login name assigned by the NetBSD Project.
#		The default is the local login name.
#
#	PKGSRC_CHANGES
#		The path to the CHANGES file to which the entry
#		is appended.
#		The default is ${PKGSRCDIR}/doc/CHANGES-YYYY.
#
#	Example usage:
#		% cd /usr/pkgsrc/category/package
#		% make changes-entry CTYPE=Added
#
# commit-changes-entry:
# cce:
#	Like the above, plus the CHANGES file is committed.
#

CTYPE?=			Updated
NETBSD_LOGIN_NAME?=	${_NETBSD_LOGIN_NAME_cmd:sh}
PKGSRC_CHANGES?=	${PKGSRCDIR}/doc/CHANGES-${_CYEAR_cmd:sh}

_CYEAR_cmd=		${DATE} -u +%Y
_CDATE_cmd=		${DATE} -u +%Y-%m-%d
_NETBSD_LOGIN_NAME_cmd=	${ID} -nu

.if ${CTYPE} == "Updated"
_CE_MSG1=	Updated ${PKGPATH} to ${PKGVERSION}
.elif ${CTYPE} == "Removed"
_CE_MSG1=	Removed ${PKGPATH}
.elif ${CTYPE} == "Added"
_CE_MSG1=	Added ${PKGPATH} version ${PKGVERSION}
.elif ${CTYPE} == "Renamed" || ${CTYPE} == "Moved"
.  if defined(TO)
.    if exists(${PKGSRCDIR}/${TO})
_CE_MSG1=	${CTYPE} ${PKGPATH} to ${TO}
.    else
_CE_ERRORS+=	"[developer.mk] The package ${TO} does not exist."
.    endif
.  else
_CE_ERRORS+=	"[developer.mk] The TO variable must be set."
.  endif
.else
_CE_ERRORS+=	"[developer.mk] Invalid value "${CTYPE:Q}" for CTYPE."
.endif
_CE_MSG2=	[${NETBSD_LOGIN_NAME} ${_CDATE_cmd:sh}]
_CE_MSG=	${_CE_MSG1} ${_CE_MSG2}

_CCE_CHANGES=	${PKGSRCDIR}/doc/CHANGES-${_CYEAR_cmd:sh}

.PHONY: changes-entry
changes-entry: ce-error-check
	${RUN} ${ECHO} "	"${_CE_MSG:Q} >> ${PKGSRC_CHANGES:Q}

commit-changes-entry cce: .PHONY ce-error-check
	@${STEP_MSG} "Updating ${PKGSRC_CHANGES:T}"
	${RUN} cd ${PKGSRCDIR}/doc && cvs update ${_CCE_CHANGES:T}
	@${STEP_MSG} "Adding the change"
	${RUN} ${ECHO} "	"${_CE_MSG:Q} >> ${_CCE_CHANGES}
	@${STEP_MSG} "Committing the change"
	${RUN} cd ${PKGSRCDIR}/doc && cvs commit -m ${_CE_MSG1:Q} ${_CCE_CHANGES:T}

ce-error-check:
.if defined(_CE_ERRORS) && !empty(_CE_ERRORS:M*)
	${RUN} for msg in ${_CE_ERRORS}; do ${ERROR_MSG} "$$msg"; done; exit 1
.else
	@${DO_NADA}
.endif
