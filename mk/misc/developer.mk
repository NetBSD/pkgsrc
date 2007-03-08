# $NetBSD: developer.mk,v 1.3 2007/03/08 23:38:43 rillig Exp $
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
#		"Updated", "Renamed", "Moved", of "Removed".
#		The default is "Updated".
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

CTYPE?=			Updated
NETBSD_LOGIN_NAME?=	${_NETBSD_LOGIN_NAME_cmd:sh}
PKGSRC_CHANGES?=	${PKGSRCDIR}/doc/CHANGES-${_CYEAR_cmd:sh}

_CYEAR_cmd=		${DATE} -u +%Y
_CDATE_cmd=		${DATE} -u +%Y-%m-%d
_NETBSD_LOGIN_NAME_cmd=	${ID} -nu

_CTYPE1=	"	"${CTYPE:Q}" "${PKGPATH:Q}
.if !empty(CTYPE:MUpdated)
_CTYPE2=	" to "${PKGVERSION:Q}
.elif !empty(CTYPE:MAdded)
_CTYPE2=	" version "${PKGVERSION:Q}
.elif !empty(CTYPE:MRenamed) || !empty(CTYPE:MMoved)
_CTYPE2=	" to XXX"
.else
_CTYPE2=
.endif
_CTYPE3=	" ["${NETBSD_LOGIN_NAME:Q}" "${_CDATE_cmd:sh:Q}"]"

.PHONY: changes-entry
changes-entry:
	${RUN} \
	${ECHO} ${_CTYPE1}${_CTYPE2}${_CTYPE3} >> ${PKGSRC_CHANGES:Q}
