# $NetBSD: developer.mk,v 1.21 2014/02/20 10:12:22 obache Exp $
#
# Public targets for developers:
#
# changes-entry-noupdate:
#	Appends a correctly-formatted entry to the pkgsrc CHANGES file,
#	and removes any TODO entries that were completed with this
#	update from the TODO file.
#	The CHANGES and TODO files are presumed to be up to date and writable.
#	Note that the first assumption is often wrong and that the
#	second is wrong for those that set CVSREAD.
#
#	Command-line variables:
#
#	CTYPE
#		The type of entry to add. Must be one of "Added",
#		"Updated", "Renamed" (when the PKGNAME has changed),
#		"Moved" (when the package has a new directory, but the
#		PKGNAME is still the same), or "Removed".
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
#	PKGSRC_TODO
#		The path to the TODO file from which now possibly
#		obsolete entries are removed
#		The default is ${PKGSRCDIR}/TODO.
#
#	USE_NETBSD_REPO
#		Explicitly use cvs.netbsd.org:/cvsroot for all cvs commands
#		issues by changes-entry and co.
#
#	Example usage:
#		% cd /usr/pkgsrc/category/package
#		% make changes-entry CTYPE=Added
#
# changes-entry:
#	Like changes-entry-noupdate, plus the CHANGES and TODO files
#	are updated, and if not writable, "cvs edit" is done.
#
# commit-changes-entry:
# cce:
#	Like changes-entry, plus the CHANGES and TODO files are committed.
#
# upload-distfiles:
# 	Upload files that wish to provide distfiles that others may fetch.
#	It only upload distfiles that are freely re-distributable by setting
# 	NO_SKIP (see mk/fetch/bsd.fetch-vars.mk).
#
# Keywords: commit update add rename changes upload
#

CTYPE?=			Updated
NETBSD_LOGIN_NAME?=	${_NETBSD_LOGIN_NAME_cmd:sh}

PKGSRC_CHANGES_DIR=	${PKGSRCDIR}/doc/
PKGSRC_CHANGES_BASE=	CHANGES-${_CYEAR_cmd:sh}
PKGSRC_CHANGES?=	${PKGSRC_CHANGES_DIR}/${PKGSRC_CHANGES_BASE}
PKGSRC_TODO?=		${PKGSRC_CHANGES_DIR}/TODO

_CYEAR_cmd=		${DATE} -u +%Y
_CDATE_cmd=		${DATE} -u +%Y-%m-%d
_NETBSD_LOGIN_NAME_cmd=	${ID} -nu

USE_NETBSD_REPO?=	no

.if !empty(USE_NETBSD_REPO:M[Yy][Ee][Ss])
_NB_CVSROOT=	-d ${NETBSD_LOGIN_NAME:Q}@cvs.NetBSD.org:/cvsroot
.endif

.if !empty(CTYPE:tl:Mup*)				# updated
_CE_MSG1=	Updated ${PKGPATH} to ${PKGVERSION}
.elif !empty(CTYPE:tl:Mrem*) || !empty(CTYPE:tl:Mrm)	# removed
# XXX Check OLDNAME, and if so add " successor ${OLDNAME}".
_CE_MSG1=	Removed ${PKGPATH}
.elif !empty(CTYPE:tl:Madd*)				# added
_CE_MSG1=	Added ${PKGPATH} version ${PKGVERSION}
.elif !empty(CTYPE:tl:Mren*) || !empty(CTYPE:tl:Mmov*) || !empty(CTYPE:tl:Mmv)
.  if !defined(TO)
_CE_ERRORS+=	"[developer.mk] The TO variable must be set."
.  elif !exists(${PKGSRCDIR}/${TO})
_CE_ERRORS+=	"[developer.mk] The package directory ${TO} does not exist."
.  endif
.  if !empty(CTYPE:M[Mm]*)
_CE_MSG1=	Moved ${PKGPATH} to ${TO}
.  else
_CE_MSG1=	Renamed ${PKGPATH} to ${TO}
.  endif
.else
_CE_ERRORS+=	"[developer.mk] Invalid value "${CTYPE:Q}" for CTYPE."
.endif
_CE_MSG2=	[${NETBSD_LOGIN_NAME} ${_CDATE_cmd:sh}]
_CE_MSG=	${_CE_MSG1} ${_CE_MSG2}

# XXX Accumulate commit message during each operation, so that a final
# commit operation will have a sensible message with all of the
# previous operations.

# XXX Fail if uid is 0, or perhaps != CVS meta files owner, to catch
# the case of invoking these targets as root.

# Targets for the update, add, commit elementary operations.
changes-entry-update: .PHONY ce-error-check
	@${STEP_MSG} "Updating ${PKGSRC_CHANGES:T} and ${PKGSRC_TODO:T}"
	${RUN} cd ${PKGSRC_CHANGES_DIR} && cvs ${_NB_CVSROOT} update ${PKGSRC_CHANGES:T} ${PKGSRC_TODO:T}
	${RUN} cd ${PKGSRC_CHANGES_DIR} && test -w ${PKGSRC_CHANGES:T} || cvs ${_NB_CVSROOT} edit ${PKGSRC_CHANGES:T}
	${RUN} cd ${PKGSRC_CHANGES_DIR} && test -w ${PKGSRC_TODO:T} || cvs ${_NB_CVSROOT} edit ${PKGSRC_TODO:T}

changes-entry-add: .PHONY ce-error-check
	@${STEP_MSG} "Adding the change"
	${RUN} ${ECHO} "	"${_CE_MSG:Q} >> ${PKGSRC_CHANGES}

todo-entry-remove:
	${RUN} PKG_ADMIN=${PKG_ADMIN_CMD:Q} ${SH} ${PKGSRCDIR}/mk/scripts/remove_todo ${PKGSRC_TODO} ${PKGBASE} ${PKGVERSION}

changes-entry-commit: .PHONY ce-error-check
	@${STEP_MSG} "Committing the change"
	${RUN} cd ${PKGSRC_CHANGES_DIR} && cvs ${_NB_CVSROOT} commit -m ${_CE_MSG1:Q} ${PKGSRC_CHANGES:T} ${PKGSRC_TODO:T}

ce-error-check: .PHONY
.if defined(_CE_ERRORS) && !empty(_CE_ERRORS:M*)
	${RUN} for msg in ${_CE_ERRORS}; do ${ERROR_MSG} "$$msg"; done; exit 1
.else
	@${DO_NADA}
.endif

# Public targets
changes-entry-noupdate: .PHONY ce-error-check changes-entry-add todo-entry-remove
	@${DO_NADA}

changes-entry: .PHONY ce-error-check changes-entry-update changes-entry-add todo-entry-remove
	@${DO_NADA}

commit-changes-entry cce: .PHONY ce-error-check changes-entry-update changes-entry-add todo-entry-remove changes-entry-commit
	@${DO_NADA}

.PHONY: upload-distfiles
.if defined(NO_SRC_ON_FTP) || empty(_ALLFILES)
upload-distfiles:
	@${DO_NADA}
.else
.  if defined(EMUL_PLATFORMS) && !empty(EMUL_PLATFORMS)
upload-distfiles:
.    for _platform_ in ${EMUL_PLATFORMS}
	${RUN} ${MAKE} ${MAKEFLAGS} do-upload-distfiles NO_SKIP=yes	\
		_BOOTSTRAP_VERBOSE= EMUL_PLATFORM=${_platform_}
.    endfor
.  else
upload-distfiles: do-upload-distfiles
.  endif

.PHONY: do-upload-distfiles
do-upload-distfiles: checksum
	${RUN}								\
	disthost='ftp.NetBSD.org';					\
	distdir='~ftp/pub/pkgsrc/distfiles';				\
	${STEP_MSG} "Checking uploaded files";				\
	uploaded_files=`${ECHO} "(cd $${distdir} && /bin/ls -1d ${_ALLFILES}) 2>/dev/null || ${TRUE}" | ssh $${disthost} /bin/sh`;	\
	pending_files="";						\
	for file in ${_ALLFILES}; do					\
		found=0;						\
		for ufile in "" $${uploaded_files}; do			\
			if ${TEST} x$${file} = x$${ufile}; then		\
				found=1;				\
				break;					\
			fi;						\
		done;							\
		if ${TEST} $${found} -ne 1; then			\
			pending_files="$${pending_files} $${file}";	\
		fi;							\
	done;								\
	if ${TEST} -n "$${pending_files}"; then				\
		${STEP_MSG} "Uploading distfiles";			\
		cd ${DISTDIR} && ${TAR:U${TOOLS_PLATFORM.tar:Utar}} cf - $${pending_files} | 	\
			ssh "$${disthost}" /bin/tar xpf - -C "$${distdir}";\
	fi
.endif

