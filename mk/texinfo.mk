# $NetBSD: texinfo.mk,v 1.8.2.1 2003/02/14 21:52:49 agc Exp $
#
# This Makefile fragment is included by packages that provide info files.
#

.if !defined(TEXINFO_MK)
TEXINFO_MK=	# defined

# Does the system have the GNU texinfo tools and if yes, what version are they?
_INSTALL_INFO=
.for _i_ in /usr/bin/install-info /sbin/install-info
.  if exists(${_i_})
_INSTALL_INFO=	${_i_}
.  endif
.endfor
.if !empty(_INSTALL_INFO)
.  if !defined(INSTALL_INFO_VERSION)
_INSTALL_INFO_VERSION_OUTPUT!=  ${_INSTALL_INFO} --version 2>/dev/null
# If the install-info version contains useful information outside [0-9].[0-9],
# the following would have to be changed as well as the comparison below
INSTALL_INFO_VERSION=${_INSTALL_INFO_VERSION_OUTPUT:M[0-9]*.[0-9]*:C/[^0-9.]//}
MAKEFLAGS+=		INSTALL_INFO_VERSION=${INSTALL_INFO_VERSION}
.  endif
.endif

# Minimum required version for the GNU texinfo tools.
TEXINFO_REQD?=	3.12

# Sort out if we need the version provided by devel/gtexinfo.
.if defined(INSTALL_INFO_VERSION)
.  if ${INSTALL_INFO_VERSION} < ${TEXINFO_REQD}
_NEED_TEXINFO=	# defined
.  endif
.else
_NEED_TEXINFO=	# defined
.endif

.if defined(_NEED_TEXINFO)
DEPENDS+=		gtexinfo>=${TEXINFO_REQD}:../../devel/gtexinfo
_GTEXINFO_PREFIX_DEFAULT=${LOCALBASE}
EVAL_PREFIX+=		_GTEXINFO_PREFIX=gtexinfo
INSTALL_INFO=	${_GTEXINFO_PREFIX}/bin/install-info
MAKEINFO=	${_GTEXINFO_PREFIX}/bin/makeinfo
.else
INSTALL_INFO=	${_INSTALL_INFO}
MAKEINFO=	/usr/bin/makeinfo	# we assume it!
.endif

#
# Advertise in environment which install-info and makeinfo should be used.
#
CONFIGURE_ENV+=	MAKEINFO="${MAKEINFO}" INSTALL_INFO="${INSTALL_INFO}"
MAKE_ENV+=	MAKEINFO="${MAKEINFO}" INSTALL_INFO="${INSTALL_INFO}"

#
# Another way would be to use ${SED} to substitute @MAKEINFO@, @INSTALL_INFO@
# and bare makeinfo and install-info words  in target rules commands and in
# Makefiles variable assignments for the files matching ${TEXINFO_PATTERNS}.
#
# Note: there are embedded tabs in some variables below.
#
TEXINFO_OVERRIDE?=	NO

.if defined(TEXINFO_OVERRIDE) && (${TEXINFO_OVERRIDE} == "YES")
TEXINFO_PATTERNS+=	Makefile.in
# replace @MAKEINFO@ and @INSTALL_INFO@ respectively with ${MAKEINFO} and
# ${INSTALL_INFO}
TEXINFO_VAR_SUBST+=	MAKEINFO=${MAKEINFO:Q}
TEXINFO_VAR_SUBST+=	INSTALL_INFO=${INSTALL_INFO:Q}
TEXINFO_SUBST_SED+=	${TEXINFO_VAR_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}
# replace bare makeinfo and install-info in MAKEINFO and INSTALL_INFO variables
# assignments
TEXINFO_SUBST_SED+=	-e 's!^MAKEINFO[ 	]*=[ 	]*makeinfo[ 	]*\(.*\)$$!MAKEINFO = ${MAKEINFO} \1!'
TEXINFO_SUBST_SED+=	-e 's!^INSTALL_INFO[ 	]*=[ 	]*install-info[ 	]*\(.*\)$$!INSTALL_INFO = ${INSTALL_INFO} \1!'
# replace bare makeinfo and install-info commands in Makefile target rules
TEXINFO_SUBST_SED+=	-e "s!^\(	.*\)\([ 	]\)makeinfo\([ 	]\)!\1\2${MAKEINFO}\3!g"
TEXINFO_SUBST_SED+=	-e "s!^\(	.*\)\([ 	']\)install-info\([ 	]\)!\1\2${INSTALL_INFO}\3!g"

_CONFIGURE_PREREQ+=	texinfo-override
texinfo-override:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	(for _PATTERN in ${TEXINFO_PATTERNS}; do			\
	  ${FIND} ${WRKSRC} -type f -name "$$_PATTERN" -print;		\
	done; ) | ( while read _F ; do					\
		${SED} ${TEXINFO_SUBST_SED} "$$_F" > "$$_F.new" &&	\
		${MV} "$$_F.new" "$$_F";				\
	done )
.endif # TEXINFO_OVERRIDE

.endif # TEXINFO_MK
