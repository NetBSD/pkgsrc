# changes-entry appends a correctly-formatted entry to the pkgsrc
# CHANGES file.
#
# The following variables may be set:
#
#    CTYPE is the type of entry to add and is one of "Added", "Updated",
#	"Renamed", "Moved", of "Removed".  The default CTYPE is "Updated".
#
#    NETBSD_LOGIN_NAME is the login name assigned by the NetBSD Project.
#	It defaults to the local login name.
#
#    PKGSRC_CHANGES is the path to the CHANGES file to which the entry
#	is appended.  It defaults to ${PKGSRCDIR}/doc/CHANGES-YYYY.
#
# Example usage:
#
#	% cd /usr/pkgsrc/category/package
#	% make changes-entry CTYPE=Added
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
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} ${_CTYPE1}${_CTYPE2}${_CTYPE3} >> ${PKGSRC_CHANGES:Q}

