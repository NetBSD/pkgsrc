# $NetBSD: redmine.mk,v 1.3 2021/08/31 15:05:02 taca Exp $

.if !defined(_RUBY_REDMINE_MK)
_RUBY_REDMINE_MK=	# defined

.include "../../lang/ruby/rubyversion.mk"

#
# === User-settable variables ===
#
# RM_VERSION_DEFAULT
#	Select default Redmine version.
#
#	Possible values: 41 42
#	Default: 42
#
#
# === Package-settable variables ===
#
# RM_VERSIONS_SUPPORTED
#	Supported Redmine version.
#	Possible values: 41 42
#	Default: 42
#
#
# === Defined variables ===
#
# RM_VER
#	Redmine version.
#	Possible values: 41 42
#	Default: 42
#
# RM_DIR
#	Redmine directory.
#

.if ${RUBY_VER} == "26"
RM_VERSION_DEFAULT?=	42
RM_VERSIONS_SUPPORTED?=	42 41
.elif ${RUBY_VER} == "27"
RM_VERSION_DEFAULT?=	42
RM_VERSIONS_SUPPORTED?=	42
.else
.error "There is no remine support Ruby ${RUBY_VERSION}"
.endif

RM_VERSION?=	# empty
RM_VER?=	# empty

.if ${RM_VERSION} == ""
.  for rv in ${RM_VERSIONS_SUPPORTED}
.    if exists(${PREFIX}/share${RUBY_PKGPREFIX}-redmine${rv})
RM_VER=		${rv}
.    endif
.  endfor
.  if ${RM_VER} == ""
RM_VER=		${RM_VERSION_DEFAULT}
.  endif
.else
RM_MAJOR=	${RM_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
RM_MINOR=	${RM_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}

RM_VER=		${RM_MAJOR}${RM_MINOR}
.endif

.if "${RM_VER}" == "41" || "${RM_VER}" == "42"
REDMINE_DEPENDS=	${RUBY_PKGPREFIX}-redmine${RM_VER}-[0-9]*:../../devel/ruby-redmine${RM_VER}
RM_PLUGINDIR=		${RM_DIR}/plugins
RM_THEMEDIR=		${RM_DIR}/public/themes
.else
PKG_FAIL_REASON+=	"Unknown Redmine version specified: ${RM_VER}"
.endif

RM_DIR=		share/${RUBY_PKGPREFIX}-redmine${RM_VER}

INSTALL_ENV+=	RM_DIR=${RM_DIR}
FILES_SUBST+=	RM_DIR=${RM_DIR}
PLIST_SUBST+=	RM_DIR=${RM_DIR:Q} GEM_HOME=${GEM_HOME}
PLIST_SUBST+=	RM_PLUGINDIR=${RM_PLUGINDIR} RM_THEMEDIR=${RM_THEMEDIR}

.if !empty(GEM_EXTSDIR)
PRINT_PLIST_AWK+=	/^${GEM_EXTSDIR:S|/|\\/|g}/ \
				{ gsub(/${GEM_EXTSDIR:S|/|\\/|g}/, "$${GEM_EXTSDIR}") }
.endif
PRINT_PLIST_AWK+=	/^${GEM_HOME:S|/|\\/|g}/ \
				{ gsub(/${GEM_HOME:S|/|\\/|g}/, "$${GEM_HOME}") }
PRINT_PLIST_AWK+=	/^${RM_PLUGINDIR:S|/|\\/|g}/ { gsub(/^${RM_PLUGINDIR:S|/|\\/|g}/, "$${RM_PLUGINDIR}"); }
PRINT_PLIST_AWK+=	/^${RM_THEMEDIR:S|/|\\/|g}/ { gsub(/^${RM_THEMEDIR:S|/|\\/|g}/, "$${RM_THEMEDIR}"); }
PRINT_PLIST_AWK+=	/^${RM_DIR:S|/|\\/|g}/ { gsub(/^${RM_DIR:S|/|\\/|g}/, "$${RM_DIR}"); }

.endif	# _RUBY_REDMINE_MK
