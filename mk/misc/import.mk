# $NetBSD: import.mk,v 1.5 2011/11/13 23:09:17 joerg Exp $
#

# import:
#	Imports a package from the outside into pkgsrc.
#
#	Command line parameters:
#
#	FROM (optional when you are in a pkgsrc-wip package)
#		The source where the package comes from. A common value
#		is "pkgsrc-wip" or an empty string.
#
#	CATEGORY
#		The main category of the package. This is where the package
#		gets imported.
#
#	BY (optional)
#		The name or mail address of the original package builder.
#		This is used in the commit message.
#
#	NETBSD_LOGIN_NAME
#		The name of your account on cvs.NetBSD.org. Is used for
#		recording the change in doc/CHANGES.
#
# keywords: wip pkgsrc-wip
#

_IMPORT_ERRORS=		# none

_IMPORT_FROM=		# nothing but a leading space
.if defined(FROM)
.  if !empty(FROM)
_IMPORT_FROM+=		from ${FROM}
.  endif
.elif !empty(PKGPATH:Mwip/*)
_IMPORT_FROM+=		from pkgsrc-wip
.else
_IMPORT_ERRORS+=	"[import.mk] You must set FROM."
.endif
CATEGORY?=	${CATEGORIES:[1]}
.if ${CATEGORY:U} == ""
_IMPORT_ERRORS+=	"[import.mk] You must set CATEGORY."
.endif
.if exists(${.CURDIR}/TODO)
_IMPORT_ERRORS+=	"[import.mk] Don't import packages that have something TODO."
.endif
.if exists(${PKGSRCDIR}/${CATEGORY:Unonexistent}/${PKGPATH:T}/Makefile)
_IMPORT_REMOVE_BEFORE_UPDATE=yes
.else
_IMPORT_REMOVE_BEFORE_UPDATE=no
.endif
.if ${_EXPERIMENTAL:U""} != "yes"
_IMPORT_ERRORS+=	"[import.mk] The \"import\" target is experimental."
.endif

_IMPORT_YEAR!=		date -u +%Y
_IMPORT_TODAY!=		date -u +%Y-%m-%d
_IMPORT_CHANGES=	${PKGSRCDIR}/doc/CHANGES-${_IMPORT_YEAR}

.PHONY: import _import-check _import-import _import-add-change _import-remove
import: _import-check _import-import _import-add-change _import-remove

_import-check:
.if !empty(_IMPORT_ERRORS)
	${RUN} ${_IMPORT_ERRORS:@e@ ${ERROR_MSG} ${e:Q}; @} ${FALSE}
.endif
	${RUN} pkglint --import -Wall

_import-import:
	@${STEP_MSG} "Importing ${PKGNAME}."
	${RUN} \
	import_msg=`set -e;						\
	{	${ECHO} "Imported ${PKGBASE}${_IMPORT_FROM}.";		\
		${ECHO} "";						\
		${CAT} DESCR;						\
		case ${BY:Q}"" in					\
		"")	;;						\
		*)	${ECHO} ""; ${ECHO} "Packaged by ${BY}.";;	\
		esac;							\
	}`;								\
	cvs -d cvs.netbsd.org:/cvsroot import				\
		-m "$$import_msg"					\
		pkgsrc/${CATEGORY}/${PKGPATH:T}				\
		TNF pkgsrc-base

_import-add-change:
	@${STEP_MSG} "Adding CHANGES entry."
	${RUN} cd ${PKGSRCDIR}/doc && cvs update ${_IMPORT_CHANGES:T}
	${RUN} printf "\\tAdded %s version %s [%s %s]\\n"		\
		${CATEGORY}/${PKGPATH:T} ${PKGVERSION}			\
		${NETBSD_LOGIN_NAME} ${_IMPORT_TODAY}			\
		>> ${_IMPORT_CHANGES}
	${RUN} cd ${PKGSRCDIR}/doc && cvs commit			\
		-m "Imported ${CATEGORY}/${PKGPATH:T}${_IMPORT_FROM}."	\
		${_IMPORT_CHANGES:T}
.if ${_IMPORT_REMOVE_BEFORE_UPDATE} == "yes"
	@${STEP_MSG} "Removing local copy."
	${RUN} cd ${PKGSRCDIR}/${CATEGORY}/${PKGPATH:T} && rm -f *
.endif
	@${STEP_MSG} "Loading the new package from CVS."
	${RUN} cd ${PKGSRCDIR}/${CATEGORY}/${PKGPATH:T} && rm -f *
	${RUN} cd ${PKGSRCDIR}/${CATEGORY} && cvs update Makefile ${PKGPATH:T}
	@${STEP_MSG} "Adding the package to the category Makefile."
	${RUN} cd ${PKGSRCDIR}/${CATEGORY} && (pkglint -F >/dev/null || ${TRUE}) && pkglint -q
	@${STEP_MSG} "Committing the modified category Makefile."
	${RUN} cd ${PKGSRCDIR}/${CATEGORY} && cvs commit -m "Added ${PKGPATH:T}." Makefile

_IMPORT_REMOVE_FILES!=	ls -d * patches/* files/* 2>/dev/null || ${TRUE}
_IMPORT_REMOVE_FILES:=	${_IMPORT_REMOVE_FILES:NCVS:N*/CVS}
_import-remove:
	${RUN} \
	case ${PKGPATH} in						\
	wip/*)								\
		${STEP_MSG} "Removing ${PKGNAME} from pkgsrc-wip.";	\
		cvs rm -f ${_IMPORT_REMOVE_FILES};			\
		cvs commit -m "Imported into pkgsrc as ${CATEGORY}/${PKGBASE}.";; \
	esac
