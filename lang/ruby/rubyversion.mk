# $NetBSD: rubyversion.mk,v 1.281 2024/06/15 15:43:51 taca Exp $
#

# This file determines which Ruby version is used as a dependency for
# a package.
#
#
# === User-settable variables ===
#
# RUBY_VERSION_DEFAULT
#	The preferred Ruby version to use.
#
#		Possible values: 31 32 33
#		Default: 32
#
# RUBY_BUILD_DOCUMENT
#	Build documentation of this package so that installs formatted
#	documentation.  It is also used in each package.
#
#		Possible values: Yes No
#		Default: Yes
#
# === Infrastructure variables ===
#
# RUBY_VERSION_REQD
#	Ruby version to use. This variable should not be set in
#	packages.  Normally it is used by bulk build tools.
#
#		Possible values: ${RUBY_VERSIONS_ACCEPTED}
#		Default:         ${RUBY_VERSION_DEFAULT}
#
# === Package-settable variables ===
#
# RUBY_VERSIONS_ACCEPTED
#	The Ruby versions that are acceptable for the package.
#
#		Possible values: 31 32 33
#		Default: 32 31 33
#
# RUBY_VERSIONS_INCOMPATIBLE
#	The Ruby versions that are incompatible for the package.
#
#		Possible values: 31 32 33
#		Default: empty
#
# RUBY_NOVERSION
#	If "Yes", the package dosen't depend on any version of Ruby, such
#	as an editing mode for Emacs.  In this case, package's name would begin
#	with "ruby-".  Otherwise, the package's name begins with
#	${RUBY_PKGPREFIX}.
#
#		Possible values: Yes No
#		Default: No
#
# RUBY_DYNAMIC_DIRS
#	Build dynamic PLIST from directories.
#
#	Default: (empty)
#
# RUBY_ENCODING_ARG
#
#	Optional encoding argument for shebang line.
#
#	Default: (empty)
#
# === Defined variables ===
#
# RUBY_VER
#	Really selected version of ruby.
#
#		Possible values: 31 32 33
#
#	Use this variable in pkgsrc's Makefile
#
# RUBY_PKGPREFIX
#	Prefix part for Ruby-based packages.  It is recommended to
#	use RUBY_PKGPREFIX with Ruby-related packages since you can supply
#	different binary packages for each version of Ruby.
#
#		Possible values: ruby31 ruby32 ruby33
#
# RUBY_ABI_VERSION
#	Ruby's ABI version.
#
# RUBY_DLEXT
#	Suffix of extention library.
#
# RUBY_SLEXT
#	Suffix of shared library.
#
# RUBY
#	Full path of ruby command.
#
# RDOC
#	Full path of rdoc command.
#
# RUBY_NAME
#	Name of ruby command.
#
# RUBYGEM_NAME
#	Name of gem command.
#
# RAKE_NAME
#	Name of rake command.
#
# RUBY_SUFFIX
#	Extra string for each ruby commands; ruby, irb and so on.
#
#		Possible values: 31 32 33
#
# RUBY_VERSION
#	Version of Ruby's version.
#
# RUBY_BASE
#	Name of ruby base package's name.
#
# RUBY_SRCDIR
#	Relative path to directory of base ruby package.
#
# RUBY_SHLIBVER
#	Suffix of libruby shared library's version.
#
# RUBY_SHLIB
#	String after libruby shared library.
#
# RUBY_SHLIBALIAS
#	Symblic link with libruby shared library with major version only.
#
# RUBY_STATICLIB
#	Name of libruby static library.
#
# RUBY_VER_DIR
#	Name of version directory under each library (and more) directories.
#
# RUBY_ARCH
#	Name of architecture-dependent directory name.
#
# RUBY_INC
#	machine independent include directory of ruby.
#
# RUBY_ARCHINC
#	machine dependent include directory of ruby.
#
# RUBY_LIB_BASE
#	common relative path of ruby's library.
#
# RUBY_LIB
#	version specific relative path of ruby's library.
#
# RUBY_ARCHLIB
#	version specific and machine dependent relative path of ruby's library.
#
# RUBY_SITELIB_BASE
#	common site local directory.
#
# RUBY_SITELIB
#	version specific site local directory.
#
# RUBY_SITEARCHLIB
#	version specific and machine dependent site local directory.
#
# RUBY_VENDORLIB_BASE
#	common vendor (pkgsrc) directory.
#
# RUBY_VENDORLIB
#	version specific vendor local directory.
#
# RUBY_VENDORARCHLIB
#	version specific and machine dependent vendor local directory.
#
# RUBY_DOC
#	version specific document direcotry.
#
# RUBY_EG
#	version specific examples direcotry.
#
# RUBY_GEM_BASE
#	common GEM directory.
#
# GEM_HOME
#	version specific GEM directory.
#
# RUBY_RIDIR
#	common ri directory.
#
# RUBY_BASERIDIR
#	version specific ri directory.
#
# RUBY_SYSRIDIR
#	version specific system ri directory.
#
# RUBY_SITERIDIR
#	version specific site ri directory.
#
# === supporting scripts ===
#
# UPDATE_GEMSPEC
#	a tool to modify gemspec file.
#
# Keywords: ruby
#

.if !defined(_RUBYVERSION_MK)
_RUBYVERSION_MK=	# defined

.include "../../mk/bsd.prefs.mk"

.if defined(PKGNAME_REQD)
.  if !empty(PKGNAME_REQD:Mruby[0-9][0-9]-*)
_RUBY_VERSION_REQD:=	${PKGNAME_REQD:C/ruby([0-9][0-9])-.*/\1/}
RUBY_VERSION_REQD?=	${PKGNAME_REQD:C/ruby([0-9][0-9])-.*/\1/}
.  endif
.endif

# current supported Ruby's version
RUBY31_VERSION=		3.1.6
RUBY32_VERSION=		3.2.4
RUBY33_VERSION=		3.3.3

# current API compatible version; used for version of shared library
RUBY31_API_VERSION=	3.1.0
RUBY32_API_VERSION=	3.2.0
RUBY33_API_VERSION=	3.3.0

#
RUBY_VERSION_DEFAULT?=	32

# supported Ruby's version
RUBY_VERSIONS_SUPPORTED=	31 32 33

RUBY_VERSIONS_ACCEPTED?=	32 31 33
RUBY_VERSIONS_INCOMPATIBLE?=

.if empty(RUBY_VERSIONS_SUPPORTED:M${RUBY_VERSION_DEFAULT})
.  error Unsupported RUBY_VERSION_DEFAULT: ${RUBY_VERSION_DEFAULT}
.endif

.for rv in ${RUBY_VERSIONS_ACCEPTED}
.  if empty(RUBY_VERSIONS_INCOMPATIBLE:M${rv})
_RUBY_VERSIONS_ACCEPTED+=	${rv}
.  endif
.endfor

.if defined(RUBY_VERSION_REQD)
.  for rv in ${_RUBY_VERSIONS_ACCEPTED}
.    if "${rv}" == ${RUBY_VERSION_REQD}
RUBY_VER=	${rv}
.    endif
.  endfor
.elif !defined(RUBY_VER)
.  for rv in ${_RUBY_VERSIONS_ACCEPTED}
.    if "${rv}" == ${RUBY_VERSION_DEFAULT}
RUBY_VER=	${rv}
.    endif
.  endfor
.endif

.if !defined(RUBY_VER)
.  for rv in ${_RUBY_VERSIONS_ACCEPTED}
.    if !defined(RUBY_VER)
RUBY_VER=	${rv}
.    endif
.  endfor
.endif

RUBY_VER:=	${RUBY_VER_MAP.${RUBY_VER}:U${RUBY_VER}}

RUBY_SUFFIX?=	${_RUBY_VER_MAJOR}${_RUBY_VER_MINOR}${_RUBY_VER_TEENY}

.if ${RUBY_VER} == 31
RUBY_VERSION=		${RUBY31_VERSION}
RUBY_ABI_VERSION=	${RUBY_VERSION}
RUBY_SUFFIX=		${_RUBY_VER_MAJOR}${_RUBY_VER_MINOR}

# default gems
RUBY_ABBREV_VER=		0.1.0
RUBY_BASE64_VER=		0.1.1
RUBY_BENCHMARK_VER=		0.2.0
RUBY_BIGDECIMAL_VER=		3.1.1
RUBY_BUNDLER_VER=		2.3.27
RUBY_CGI_VER=			0.3.6
RUBY_CSV_VER=			3.2.5
RUBY_DATE_VER=			3.2.2
RUBY_DELEGATE_VER=		0.2.0
RUBY_DID_YOU_MEAN_VER=		1.6.1
RUBY_DIGEST_VER=		3.1.0
RUBY_DRB_VER=			2.1.0
RUBY_ENGLISH_VER=		0.7.1
RUBY_ERB_VER=			2.2.3
RUBY_ERROR_HIGHLIGHT_VER=	0.3.0
RUBY_ETC_VER=			1.3.0
RUBY_FCNTL_VER=			1.0.1
RUBY_FIDDLE_VER=		1.1.0
RUBY_FILEUTILS_VER=		1.6.0
RUBY_FIND_VER=			0.1.1
RUBY_FORWARDABLE_VER=		1.3.2
RUBY_GETOPTLONG_VER=		0.1.1
RUBY_IO_CONSOLE_VER=		0.5.11
RUBY_IO_NONBLOCK_VER=		0.1.0
RUBY_IO_WAIT_VER=		0.2.1
RUBY_IPADDR_VER=		1.2.4
RUBY_IRB_VER=			1.4.1
RUBY_JSON_VER=			2.6.1
RUBY_LOGGER_VER=		1.5.0
RUBY_MUTEX_M_VER=		0.1.1
RUBY_NET_HTTP_VER=		0.3.0.1
RUBY_NET_PROTOCOL_VER=		0.1.2
RUBY_NKF_VER=			0.1.1
RUBY_OBSERVER_VER=		0.1.1
RUBY_OPEN3_VER=			0.1.1
RUBY_OPENSSL_VER=		3.0.1
RUBY_OPEN_URI_VER=		0.2.0
RUBY_OPTPARSE_VER=		0.2.0
RUBY_OSTRUCT_VER=		0.5.2
RUBY_PATHNAME_VER=		0.2.0
RUBY_PP_VER=			0.3.0
RUBY_PRETTYPRINT_VER=		0.1.1
RUBY_PSTORE_VER=		0.1.1
RUBY_PSYCH_VER=			4.0.4
RUBY_RACC_VER=			1.6.0
RUBY_RDOC_VER=			6.4.1.1
RUBY_READLINE_VER=		0.0.3
RUBY_READLINE_EXT_VER=		0.1.4
RUBY_RELINE_VER=		0.3.1
RUBY_RESOLV_VER=		0.2.1
RUBY_RESOLV_REPLACE_VER=	0.1.0
RUBY_RINDA_VER=			0.1.1
RUBY_RUBY2_KEYWORDS_VER=	0.0.5
RUBY_RUBYGEMS_VER=		3.3.26
RUBY_SECURERANDOM_VER=		0.2.0
RUBY_SET_VER=			1.0.2
RUBY_SHELLWORDS_VER=		0.1.0
RUBY_SINGLETON_VER=		0.1.1
RUBY_STRINGIO_VER=		3.0.1.2
RUBY_STRSCAN_VER=		3.0.1
RUBY_SYSLOG_VER=		0.1.0
RUBY_TEMPFILE_VER=		0.1.2
RUBY_TIME_VER=			0.2.2
RUBY_TIMEOUT_VER=		0.2.0
RUBY_TMPDIR_VER=		0.1.2
RUBY_TSORT_VER=			0.1.0
RUBY_UN_VER=			0.2.0
RUBY_URI_VER=			0.12.2
RUBY_WEAKREF_VER=		0.1.1
RUBY_YAML_VER=			0.2.0
RUBY_ZLIB_VER=			2.1.1

# bundled gems
RUBY_DEBUG_VER=			1.6.3
RUBY_MATRIX_VER=		0.4.2
RUBY_MINITEST_VER=		5.15.0
RUBY_NET_FTP_VER=		0.1.4
RUBY_NET_IMAP_VER=		0.2.4
RUBY_NET_POP_VER=		0.1.1
RUBY_NET_SMTP_VER=		0.3.1.1
RUBY_POWER_ASSERT_VER=		2.0.1
RUBY_PRIME_VER=			0.1.2
RUBY_RAKE_VER=			13.0.6
RUBY_RBS_VER=			2.7.0
RUBY_REXML_VER=			3.2.5
RUBY_RSS_VER=			0.2.9
RUBY_TEST_UNIT_VER=		3.5.3
RUBY_TYPEPROF_VER=		0.21.3

.elif ${RUBY_VER} == 32
RUBY_VERSION=		${RUBY32_VERSION}
RUBY_ABI_VERSION=	${RUBY_VERSION}
RUBY_SUFFIX=		${_RUBY_VER_MAJOR}${_RUBY_VER_MINOR}

# default gems
RUBY_RUBYGEMS_VER=		3.4.9
RUBY_ABBREV_VER=		0.1.1
RUBY_BASE64_VER=		0.1.1
RUBY_BENCHMARK_VER=		0.2.1
RUBY_BIGDECIMAL_VER=		3.1.3
RUBY_BUNDLER_VER=		2.4.19
RUBY_CGI_VER=			0.3.6
RUBY_CSV_VER=			3.2.6
RUBY_DATE_VER=			3.3.3
RUBY_DELEGATE_VER=		0.3.0
RUBY_DID_YOU_MEAN_VER=		1.6.3
RUBY_DIGEST_VER=		3.1.1
RUBY_DRB_VER=			2.1.1
RUBY_ENGLISH_VER=		0.7.2
RUBY_ERB_VER=			4.0.2
RUBY_ERROR_HIGHLIGHT_VER=	0.5.1
RUBY_ETC_VER=			1.4.2
RUBY_FCNTL_VER=			1.0.2
RUBY_FIDDLE_VER=		1.1.1
RUBY_FILEUTILS_VER=		1.7.0
RUBY_FIND_VER=			0.1.1
RUBY_FORWARDABLE_VER=		1.3.3
RUBY_GETOPTLONG_VER=		0.2.0
RUBY_IO_CONSOLE_VER=		0.6.0
RUBY_IO_NONBLOCK_VER=		0.2.0
RUBY_IO_WAIT_VER=		0.3.0
RUBY_IPADDR_VER=		1.2.5
RUBY_IRB_VER=			1.6.2
RUBY_JSON_VER=			2.6.3
RUBY_LOGGER_VER=		1.5.3
RUBY_MUTEX_M_VER=		0.1.2
RUBY_NET_HTTP_VER=		0.4.1
RUBY_NET_PROTOCOL_VER=		0.2.1
RUBY_NKF_VER=			0.1.2
RUBY_OBSERVER_VER=		0.1.1
RUBY_OPEN3_VER=			0.1.2
RUBY_OPENSSL_VER=		3.1.0
RUBY_OPEN_URI_VER=		0.3.0
RUBY_OPTPARSE_VER=		0.3.1
RUBY_OSTRUCT_VER=		0.5.5
RUBY_PATHNAME_VER=		0.2.1
RUBY_PP_VER=			0.4.0
RUBY_PRETTYPRINT_VER=		0.1.1
RUBY_PSTORE_VER=		0.1.2
RUBY_PSYCH_VER=			5.0.1
RUBY_RACC_VER=			1.6.2
RUBY_RDOC_VER=			6.5.1.1
RUBY_READLINE_VER=		0.0.3
RUBY_READLINE_EXT_VER=		0.1.5
RUBY_RELINE_VER=		0.3.2
RUBY_RESOLV_REPLACE_VER=	0.1.1
RUBY_RESOLV_VER=		0.2.2
RUBY_RINDA_VER=			0.1.1
RUBY_RUBY2_KEYWORDS_VER=	0.0.5
RUBY_SECURERANDOM_VER=		0.2.2
RUBY_SET_VER=			1.0.3
RUBY_SHELLWORDS_VER=		0.1.0
RUBY_SINGLETON_VER=		0.1.1
RUBY_STRINGIO_VER=		3.0.4
RUBY_STRSCAN_VER=		3.0.5
RUBY_SYSLOG_VER=		0.1.1
RUBY_SYNTAX_SUGGEST_VER=	1.1.0
RUBY_TEMPFILE_VER=		0.1.3
RUBY_TIME_VER=			0.2.2
RUBY_TIMEOUT_VER=		0.3.1
RUBY_TMPDIR_VER=		0.1.3
RUBY_TSORT_VER=			0.1.1
RUBY_UN_VER=			0.2.1
RUBY_URI_VER=			0.12.2
RUBY_WEAKREF_VER=		0.1.2
RUBY_YAML_VER=			0.2.1
RUBY_ZLIB_VER=			3.0.0

# bundled gems
RUBY_DEBUG_VER=			1.7.1
RUBY_MATRIX_VER=		0.4.2
RUBY_MINITEST_VER=		5.16.3
RUBY_NET_FTP_VER=		0.2.1
RUBY_NET_IMAP_VER=		0.3.4.1
RUBY_NET_POP_VER=		0.1.2
RUBY_NET_SMTP_VER=		0.3.4
RUBY_POWER_ASSERT_VER=		2.0.3
RUBY_PRIME_VER=			0.1.2
RUBY_RAKE_VER=			13.0.6
RUBY_RBS_VER=			2.8.2
RUBY_REXML_VER=			3.2.5
RUBY_RSS_VER=			0.2.9
RUBY_TEST_UNIT_VER=		3.5.7
RUBY_TYPEPROF_VER=		0.21.3

.elif ${RUBY_VER} == 33
RUBY_VERSION=		${RUBY33_VERSION}
RUBY_ABI_VERSION=	${RUBY_VERSION}
RUBY_SUFFIX=		${_RUBY_VER_MAJOR}${_RUBY_VER_MINOR}

# default gems
RUBY_RUBYGEMS_VER=		3.5.11
RUBY_ABBREV_VER=		0.1.2
RUBY_BASE64_VER=		0.2.0
RUBY_BENCHMARK_VER=		0.3.0
RUBY_BIGDECIMAL_VER=		3.1.5
RUBY_BUNDLER_VER=		2.5.11
RUBY_CGI_VER=			0.4.1
RUBY_CSV_VER=			3.2.8
RUBY_DATE_VER=			3.3.4
RUBY_DELEGATE_VER=		0.3.1
RUBY_DID_YOU_MEAN_VER=		1.6.3
RUBY_DIGEST_VER=		3.1.1
RUBY_DRB_VER=			2.2.0
RUBY_ENGLISH_VER=		0.8.0
RUBY_ERB_VER=			4.0.3
RUBY_ERROR_HIGHLIGHT_VER=	0.6.0
RUBY_ETC_VER=			1.4.3
RUBY_FCNTL_VER=			1.1.0
RUBY_FIDDLE_VER=		1.1.2
RUBY_FILEUTILS_VER=		1.7.2
RUBY_FIND_VER=			0.2.0
RUBY_FORWARDABLE_VER=		1.3.3
RUBY_GETOPTLONG_VER=		0.2.1
RUBY_IO_CONSOLE_VER=		0.7.1
RUBY_IO_NONBLOCK_VER=		0.3.0
RUBY_IO_WAIT_VER=		0.3.1
RUBY_IPADDR_VER=		1.2.6
RUBY_IRB_VER=			1.13.1
RUBY_JSON_VER=			2.7.1
RUBY_LOGGER_VER=		1.6.0
RUBY_MUTEX_M_VER=		0.2.0
RUBY_NET_HTTP_VER=		0.4.1
RUBY_NET_PROTOCOL_VER=		0.2.2
RUBY_NKF_VER=			0.1.3
RUBY_OBSERVER_VER=		0.1.2
RUBY_OPEN3_VER=			0.2.1
RUBY_OPENSSL_VER=		3.2.0
RUBY_OPEN_URI_VER=		0.4.1
RUBY_OPTPARSE_VER=		0.4.0
RUBY_OSTRUCT_VER=		0.6.0
RUBY_PATHNAME_VER=		0.3.0
RUBY_PP_VER=			0.5.0
RUBY_PRETTYPRINT_VER=		0.2.0
RUBY_PRISM_VER=			0.19.0
RUBY_PSTORE_VER=		0.1.3
RUBY_PSYCH_VER=			5.1.2
RUBY_RDOC_VER=			6.6.3.1
RUBY_READLINE_VER=		0.0.4
RUBY_RELINE_VER=		0.5.7
RUBY_RESOLV_REPLACE_VER=	0.1.1
RUBY_RESOLV_VER=		0.3.0
RUBY_RINDA_VER=			0.2.0
RUBY_RUBY2_KEYWORDS_VER=	0.0.5
RUBY_SECURERANDOM_VER=		0.3.1
RUBY_SET_VER=			1.1.0
RUBY_SHELLWORDS_VER=		0.2.0
RUBY_SINGLETON_VER=		0.2.0
RUBY_STRINGIO_VER=		3.1.1
RUBY_STRSCAN_VER=		3.0.9
RUBY_SYSLOG_VER=		0.1.2
RUBY_SYNTAX_SUGGEST_VER=	2.0.0
RUBY_TEMPFILE_VER=		0.2.1
RUBY_TIME_VER=			0.3.0
RUBY_TIMEOUT_VER=		0.4.1
RUBY_TMPDIR_VER=		0.2.0
RUBY_TSORT_VER=			0.2.0
RUBY_UN_VER=			0.3.0
RUBY_URI_VER=			0.13.0
RUBY_WEAKREF_VER=		0.1.3
RUBY_YAML_VER=			0.3.0
RUBY_ZLIB_VER=			3.1.1

# bundled gems
RUBY_DEBUG_VER=			1.9.1
RUBY_MATRIX_VER=		0.4.2
RUBY_MINITEST_VER=		5.20.0
RUBY_NET_FTP_VER=		0.3.4
RUBY_NET_IMAP_VER=		0.4.9.1
RUBY_NET_POP_VER=		0.1.2
RUBY_NET_SMTP_VER=		0.4.0.1
RUBY_POWER_ASSERT_VER=		2.0.3
RUBY_PRIME_VER=			0.1.2
RUBY_RACC_VER=			1.7.3
RUBY_RAKE_VER=			13.1.0
RUBY_RBS_VER=			3.4.0
RUBY_REXML_VER=			3.2.8
RUBY_RSS_VER=			0.3.0
RUBY_TEST_UNIT_VER=		3.6.1
RUBY_TYPEPROF_VER=		0.21.9

.else
PKG_FAIL_REASON+=	"Unknown Ruby version specified: ${RUBY_VER}."
.endif

.if !empty(RUBY_VERSION)
RUBY_PATCHLEVEL=	${RUBY${RUBY_VER}_PATCHLEVEL}
RUBY_API_VERSION=	${RUBY${RUBY_VER}_API_VERSION}
.endif

# Variable assignment for multi-ruby packages
MULTI+=	RUBY_VER=${RUBY_VERS:U${RUBY_VERSION_DEFAULT}}

# RUBY_NOVERSION should be set to "Yes" if the package dosen't depend on
#	any specific version of ruby command.  In this case, package's
#	name begin with "ruby-".
#	If RUBY_NOVERSION is "No" (default), the package's name begins
#	with ${RUBY_NAME}; "ruby31", "ruby32" and so on.
#
#	It also affects to RUBY_DOC, RUBY_EG...
#
RUBY_NOVERSION?=	No

# _RUBY_VER_MAJOR, _RUBY_VER_MINOR
# is defined from version of Ruby.  It should not be used in packages'
# Makefile.
#
_RUBY_VER_MAJOR=	${RUBY_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+).*/\1/}
_RUBY_VER_MINOR=	${RUBY_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+).*/\2/}

RUBY_NAME=		ruby${RUBY_SUFFIX}
RUBYGEM_NAME=		gem${RUBY_SUFFIX}
RAKE_NAME=		rake${RUBY_SUFFIX}

.if ${RUBY_VER} >= 33
RUBY_BASE=		${RUBY_NAME}
RUBY_SRCDIR?=		../../lang/ruby${RUBY_VER}
.else
RUBY_BASE=		${RUBY_NAME}-base
RUBY_SRCDIR?=		../../lang/ruby${RUBY_VER}-base
.endif

RUBY_PKGPREFIX?=	${RUBY_NAME}

RUBY_VER_DIR=		${RUBY_API_VERSION}

.if empty(RUBY_NOVERSION:M[nN][oO])
RUBY_SUFFIX=
RUBY_NAME=		ruby
.endif

RUBY_BUILD_DOCUMENT?=	Yes

RUBY?=			${PREFIX}/bin/${RUBY_NAME}
RAKE?=			${PREFIX}/bin/${RAKE_NAME}
RDOC?=			${PREFIX}/bin/rdoc${RUBY_SUFFIX}

# ruby31 helpfully changed the config triple...
.if !empty(MACHINE_PLATFORM:MDarwin-*-aarch64) && ${RUBY_VER} >= 31
RUBY_ARCH?=	arm64-${LOWER_OPSYS}${APPEND_ELF}${LOWER_OPSYS_VERSUFFIX}${APPEND_ABI}
RUBY_EXTARCH?=	arm64-${LOWER_OPSYS}${APPEND_ELF}-${LOWER_OPSYS_VERSUFFIX}
.endif

RUBY_ARCH?=	${MACHINE_GNU_ARCH}-${LOWER_OPSYS}${APPEND_ELF}${LOWER_OPSYS_VERSUFFIX}${APPEND_ABI}

# NetBSD does not append an OS version, so we have to do this OPSYS-specific.
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "Linux"
RUBY_EXTARCH?=	${MACHINE_GNU_ARCH}-${LOWER_OPSYS}${APPEND_ELF}${LOWER_OPSYS_VERSUFFIX}
.else
RUBY_EXTARCH?=	${MACHINE_GNU_ARCH}-${LOWER_OPSYS}${APPEND_ELF}-${LOWER_OPSYS_VERSUFFIX}${APPEND_ABI}
.endif

RUBY_MAJOR_MINOR=	${_RUBY_VER_MAJOR}.${_RUBY_VER_MINOR}

#
# Ruby shared and static library version handling.
#
RUBY_SHLIBVER?=		${RUBY_VERSION:C/-.*$//}

_RUBY_SHLIB_MAJOR:=	${RUBY_SHLIBVER:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1\2/}
_RUBY_SHLIB_MINOR:=	${RUBY_SHLIBVER:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\3/}

RUBY_SHLIB?=		${RUBY_SUFFIX}.${RUBY_SLEXT}.${RUBY_SHLIBVER}
RUBY_SHLIBALIAS?=	@comment
RUBY_STATICLIB?=	${RUBY_SUFFIX}-static.a

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "Interix"
RUBY_SHLIBVER=		${_RUBY_SHLIB_MAJOR}.${_RUBY_SHLIB_MINOR}
_RUBY_SHLIBALIAS=	${RUBY_SUFFIX}.${RUBY_SLEXT}.${_RUBY_SHLIB_MAJOR}
.elif ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
RUBY_SHLIBVER=		${_RUBY_SHLIB_MAJOR}${_RUBY_SHLIB_MINOR}
.elif ${OPSYS} == "OpenBSD" || ${OPSYS} == "MirBSD"
.  if ${_RUBY_VER_MINOR} == 0
RUBY_SHLIBVER=		${_RUBY_VER_MAJOR}.${_RUBY_SHLIB_MINOR}
.  else
RUBY_SHLIBVER=		${_RUBY_VER_MAJOR}.${_RUBY_VER_MINOR}${_RUBY_SHLIB_MINOR}
.  endif
.elif ${OPSYS} == "Darwin"
RUBY_SHLIB=		${RUBY_SUFFIX}.${RUBY_SHLIBVER}.${RUBY_SLEXT}
_RUBY_SHLIBALIAS=	.${_RUBY_VER_MAJOR}.${_RUBY_VER_MINOR}.${RUBY_SLEXT}
RUBY_STATICLIB=		${RUBY_SUFFIX}.${RUBY_SHLIBVER}-static.a
.elif ${OPSYS} == "Linux"
_RUBY_SHLIBALIAS=	${RUBY_SUFFIX}.${RUBY_SLEXT}.${_RUBY_VER_MAJOR}.${_RUBY_VER_MINOR}
.elif ${OPSYS} == "SunOS"
RUBY_SHLIBVER=		${_RUBY_VER_MAJOR}
_RUBY_SHLIBALIAS=	${RUBY_SUFFIX}.${RUBY_SLEXT}.${_RUBY_VER_MAJOR}.${_RUBY_VER_MINOR}.${_RUBY_SHLIB_MINOR}
.elif ${OPSYS} == "Cygwin"
RUBY_SHLIB=		${RUBY_SUFFIX}${_RUBY_SHLIB_MAJOR}${_RUBY_SHLIB_MINOR}.dll.a
RUBY_SHLIBALIAS=	bin/cygruby${RUBY_SUFFIX}${_RUBY_SHLIB_MAJOR}${_RUBY_SHLIB_MINOR}.dll
RUBY_STATICLIB=		${RUBY_SUFFIX}${_RUBY_SHLIB_MAJOR}${_RUBY_SHLIB_MINOR}-static.a
.endif

.if !empty(_RUBY_SHLIBALIAS)
RUBY_SHLIBALIAS=	lib/libruby${_RUBY_SHLIBALIAS}
.endif

.if ${SHLIB_TYPE} == "dylib"
RUBY_DLEXT=	bundle
RUBY_SLEXT=	dylib
.else
RUBY_DLEXT=	so
RUBY_SLEXT=	so
.endif

RUBY_DISTNAME?=		ruby-${RUBY_VERSION}

#
# Use pthread library with Ruby
#
.if !empty(MACHINE_PLATFORM:MDarwin-9.*-powerpc)
# Workaround for Ruby Bug #193
# http://redmine.ruby-lang.org/issues/show/193
RUBY_USE_PTHREAD?=	no
.else
RUBY_USE_PTHREAD?=	yes
.endif

RUBY_DYNAMIC_DIRS?=	# empty

#
# common paths
#
RUBY_INC=		include/ruby-${RUBY_VER_DIR}
RUBY_ARCHINC=		${RUBY_INC}/${RUBY_ARCH}
RUBY_LIB_BASE=		lib/ruby
RUBY_LIB?=		${RUBY_LIB_BASE}/${RUBY_VER_DIR}
RUBY_ARCHLIB?=		${RUBY_LIB}/${RUBY_ARCH}
RUBY_SITELIB_BASE?=	${RUBY_LIB_BASE}/site_ruby
RUBY_SITELIB?=		${RUBY_SITELIB_BASE}/${RUBY_VER_DIR}
RUBY_SITEARCHLIB?=	${RUBY_SITELIB}/${RUBY_ARCH}
RUBY_VENDORLIB_BASE?=	${RUBY_LIB_BASE}/vendor_ruby
RUBY_VENDORLIB?=	${RUBY_VENDORLIB_BASE}/${RUBY_VER_DIR}
RUBY_VENDORARCHLIB?=	${RUBY_VENDORLIB}/${RUBY_ARCH}

RUBY_DOC?=		share/doc/${RUBY_NAME}
RUBY_EG?=		share/examples/${RUBY_NAME}

RUBY_GEM_BASE?=		${RUBY_LIB_BASE}/gems
GEM_HOME?=		${RUBY_GEM_BASE}/${RUBY_VER_DIR}
GEM_EXTSBASE=		${GEM_HOME}/extensions/${RUBY_EXTARCH}/${RUBY_VER_DIR}
GEM_PLUGINSDIR=		${GEM_HOME}/plugins
GEM_PATH?=		${PREFIX}/${GEM_HOME}
RUBYGEM=		${LOCALBASE}/bin/${RUBYGEM_NAME}

RUBY_GEM_ARCH=	${RUBY_ARCH}
#
# ri database relative path
#
RUBY_RIDIR?=		share/ri
RUBY_BASERIDIR?=	${RUBY_RIDIR}/${RUBY_VER_DIR}
RUBY_SYSRIDIR?=		${RUBY_BASERIDIR}/system
RUBY_SITERIDIR?=	${RUBY_BASERIDIR}/site

#
# MAKE_ENV
#
MAKE_ENV+=		RUBY=${RUBY:Q} RUBY_VER=${RUBY_VER:Q} \
			RUBY_VERSION_DEFAULT=${RUBY_VERSION_DEFAULT:Q} \
			RAKE=${RAKE:Q} GEM_PATH=${GEM_PATH:Q}

MAKEFLAGS+=		RUBY_VER=${RUBY_VER:Q} \
			RUBY_VERSION_DEFAULT=${RUBY_VERSION_DEFAULT:Q}
.if !empty(RUBY_RAILS_ACCEPTED)
MAKEFLAGS+=		RUBY_RAILS_ACCEPTED=${RUBY_RAILS_ACCEPTED:Q}
.endif

# list of bundled modules
RUBY_BUNDLE_MODULES= \
	abbrev base64 benchmark bigdecimal bundler cgi cmath csv date dbm \
	debug delegate did_you_mean digest drb e2mmap english erb \
	error_highlight etc fcntl fiddle fileutils find forwardable \
	getoptlong io-console io-nonblock io-wait ipaddr irb json logger \
	matrix minitest mutex_m net-ftp net-http net-imap net-pop \
	net-protocol net-smtp net-telnet nkf observer open-uri open3 \
	openssl optparse ostruct pathname power_assert pp prettyprint \
	prime prism pstore psych racc rake rbs rdoc readline reline resolv \
	resolv-replace rexml rinda rss ruby2_keywords scanf sdbm \
	securerandom set shell shellwords singleton syntax_suggest \
	stringio strscan sync syslog tempfile test-unit thwait time \
	timeout tmpdir tracer tsort typeprof un uri sync weakref webrick \
	xmlrpc yaml zlib

PLIST_RUBY_DIRS=	RUBY_INC=${RUBY_INC:Q} RUBY_ARCHINC=${RUBY_ARCHINC:Q} \
			RUBY_LIB_BASE=${RUBY_LIB_BASE:Q} \
			RUBY_LIB=${RUBY_LIB:Q} \
			RUBY_ARCHLIB=${RUBY_ARCHLIB:Q} \
			RUBY_SITELIB_BASE=${RUBY_SITELIB_BASE:Q} \
			RUBY_SITELIB=${RUBY_SITELIB:Q} \
			RUBY_SITEARCHLIB=${RUBY_SITEARCHLIB:Q} \
			RUBY_VENDORLIB_BASE=${RUBY_VENDORLIB_BASE:Q} \
			RUBY_VENDORLIB=${RUBY_VENDORLIB:Q} \
			RUBY_VENDORARCHLIB=${RUBY_VENDORARCHLIB:Q} \
			RUBY_DOC=${RUBY_DOC:Q} \
			RUBY_EG=${RUBY_EG:Q} \
			RUBY_GEM_BASE=${RUBY_GEM_BASE:Q} \
			GEM_HOME=${GEM_HOME:Q} \
			RUBY_RIDIR=${RUBY_RIDIR:Q} \
			RUBY_BASERIDIR=${RUBY_BASERIDIR:Q} \
			RUBY_SYSRIDIR=${RUBY_SYSRIDIR:Q} \
			RUBY_SITERIDIR=${RUBY_SITERIDIR:Q}

#
# substitutions
#
FILES_SUBST+=		RUBY=${RUBY:Q} RUBY_NAME=${RUBY_NAME:Q} \
			RUBY_PKGPREFIX=${RUBY_PKGPREFIX:Q} \
			RUBY_SUFFIX=${RUBY_SUFFIX} \
			RUBY_VER=${RUBY_VER:Q} \
			${PLIST_RUBY_DIRS}

MESSAGE_SUBST+=		RUBY="${RUBY}" RUBY_VER="${RUBY_VER}" \
			RUBY_VERSION="${RUBY_VERSION}" \
			RUBY_PKGPREFIX="${RUBY_PKGPREFIX}" \
			RUBY_SUFFIX=${RUBY_SUFFIX} \
			${PLIST_RUBY_DIRS:S,DIR="${PREFIX}/,DIR=",}

PLIST_SUBST+=	\
	RUBY=${RUBY:Q} RUBY_VER=${RUBY_VER:Q} \
	RUBY_PKGPREFIX=${RUBY_PKGPREFIX} RUBY_SUFFIX=${RUBY_SUFFIX} \
	RUBY_VERSION=${RUBY_VERSION:Q} 	RUBY_VER_DIR=${RUBY_VER_DIR:Q} \
	RUBY_DLEXT=${RUBY_DLEXT} RUBY_SLEXT=${RUBY_SLEXT} \
	RUBY_SHLIB=${RUBY_SHLIB:Q} RUBY_SHLIBALIAS=${RUBY_SHLIBALIAS:Q} \
	RUBY_STATICLIB=${RUBY_STATICLIB:Q} RUBY_ARCH=${RUBY_ARCH:Q} \
	GEM_EXTSBASE=${GEM_EXTSBASE} GEM_PLUGINSDIR=${GEM_PLUGINSDIR} \
	${PLIST_RUBY_DIRS:S,DIR="${PREFIX}/,DIR=",} \
	RUBY_MAJOR_MINOR=${RUBY_MAJOR_MINOR} RUBY_NAME=${RUBY_NAME}

#
# make dynamic PLIST
#
.if !empty(RUBY_DYNAMIC_DIRS)

RUBY_PLIST_DYNAMIC=	${WRKDIR}/PLIST.work

.  if !defined(PLIST_SRC)
.    if exists(${PKGDIR}/PLIST.common)
PLIST_SRC+=		${PKGDIR}/PLIST.common
.    elif exists(${PKGDIR}/PLIST)
PLIST_SRC+=		${PKGDIR}/PLIST
.    endif

PLIST_SRC+=		${RUBY_PLIST_DYNAMIC}

.    if exists(${PKGDIR}/PLIST.common_end)
PLIST_SRC+=		${PKGDIR}/PLIST.common_end
.    endif

.  endif

RUBY_PLIST_COMMENT_CMD=	\
	${ECHO} "@comment The following lines are automatically generated"
RUBY_PLIST_FILES_CMD=	( cd ${DESTDIR}${PREFIX}; \
	${FIND} ${RUBY_DYNAMIC_DIRS} \( -type f -o -type l \) -print ) | \
	${SORT} -u
RUBY_GENERATE_PLIST=	( \
			${RUBY_PLIST_COMMENT_CMD}; \
	${RUBY_PLIST_FILES_CMD} ) > ${RUBY_PLIST_DYNAMIC}
.endif

PRINT_PLIST_AWK+=	/lib\/libruby${RUBY_STATICLIB}$$/ \
			{ sub(/${RUBY_STATICLIB}/, "$${RUBY_STATICLIB}"); }
PRINT_PLIST_AWK+=	/lib\/libruby${RUBY_VER}\.${RUBY_SLEXT}/ \
			{ sub(/${RUBY_VER}\.${RUBY_SLEXT}$$/, \
			"$${RUBY_VER}.$${RUBY_SLEXT}"); }
PRINT_PLIST_AWK+=	/${RUBY_SHLIB}$$/ \
			{ sub(/${RUBY_SHLIB}$$/, "$${RUBY_SHLIB}"); }
PRINT_PLIST_AWK+=	/${RUBY_SLEXT}\.${RUBY_SHLIBVER}$$/ \
			{ sub(/${RUBY_SLEXT}\.${RUBY_SHLIBVER}$$/, \
			"$${RUBY_SLEXT}.$${RUBY_SHLIBVER}"); }
.if ${RUBY_SHLIBALIAS} != "@comment"
PRINT_PLIST_AWK+=	/${RUBY_SHLIBALIAS:S/\//\\\//}$$/ \
			{ sub(/${RUBY_SHLIBALIAS:S/\//\\\//}$$/, \
			"$${RUBY_SHLIBALIAS}"); }
.endif
PRINT_PLIST_AWK+=	/^${RUBY_ARCHINC:S|/|\\/|g}/ \
			{ gsub(/${RUBY_ARCHINC:S|/|\\/|g}/, "$${RUBY_ARCHINC}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_INC:S|/|\\/|g}/ \
			{ gsub(/${RUBY_INC:S|/|\\/|g}/, "$${RUBY_INC}"); \
			print; next; }
PRINT_PLIST_AWK+=	/\.${RUBY_DLEXT}$$/ \
			{ gsub(/${RUBY_DLEXT}$$/, "$${RUBY_DLEXT}") }
PRINT_PLIST_AWK+=	/^${RUBY_ARCHLIB:S|/|\\/|g}/ \
			{ gsub(/${RUBY_ARCHLIB:S|/|\\/|g}/, "$${RUBY_ARCHLIB}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_VENDORARCHLIB:S|/|\\/|g}/ \
			{ gsub(/${RUBY_VENDORARCHLIB:S|/|\\/|g}/, "$${RUBY_VENDORARCHLIB}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_VENDORLIB:S|/|\\/|g}/ \
			{ gsub(/${RUBY_VENDORLIB:S|/|\\/|g}/, "$${RUBY_VENDORLIB}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_SITEARCHLIB:S|/|\\/|g}/ \
			{ gsub(/${RUBY_SITEARCHLIB:S|/|\\/|g}/, "$${RUBY_SITEARCHLIB}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_SITELIB:S|/|\\/|g}/ \
			{ gsub(/${RUBY_SITELIB:S|/|\\/|g}/, "$${RUBY_SITELIB}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_SITELIB_BASE:S|/|\\/|g}/ \
			{ gsub(/${RUBY_SITELIB_BASE:S|/|\\/|g}/, "$${RUBY_SITELIB_BASE}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_VENDORLIB_BASE:S|/|\\/|g}/ \
			{ gsub(/${RUBY_VENDORLIB_BASE:S|/|\\/|g}/, "$${RUBY_VENDORLIB_BASE}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_LIB:S|/|\\/|g}/ \
			{ gsub(/${RUBY_LIB:S|/|\\/|g}/, "$${RUBY_LIB}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_DOC:S|/|\\/|g}/ \
			{ gsub(/${RUBY_DOC:S|/|\\/|g}/, "$${RUBY_DOC}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_EG:S|/|\\/|g}/ \
			{ gsub(/${RUBY_EG:S|/|\\/|g}/, "$${RUBY_EG}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_SITERIDIR:S|/|\\/|g}/ \
			{ gsub(/${RUBY_SITERIDIR:S|/|\\/|g}/, "$${RUBY_SITERIDIR}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_SYSRIDIR:S|/|\\/|g}\// \
			{ next; }

_RUBY_PRINT_PLIST_GEM+=	/^${GEM_EXTSBASE:S|/|\\/|g}/ \
			{ gsub(/${GEM_EXTSBASE:S|/|\\/|g}/, "$${GEM_EXTSBASE}"); \
			print; next; }

# Insert part of PRINT_PLIST_AWK from gem.mk
PRINT_PLIST_AWK+=	${_RUBY_PRINT_PLIST_GEM}

PRINT_PLIST_AWK+=	/\/${RUBY_NAME}/ \
			{ sub(/${RUBY_NAME}/, "$${RUBY_NAME}"); }
PRINT_PLIST_AWK+=	/^${GEM_HOME:S|/|\\/|g:S|.|\\.|g}/ \
			{ gsub(/${GEM_HOME:S|/|\\/|g}/, "$${GEM_HOME}"); }
# handle ${RUBY_SUFFIX}
PRINT_PLIST_AWK+=	/^bin\/.*${RUBY_SUFFIX}$$/ \
			{ sub(/${RUBY_SUFFIX}$$/, "$${RUBY_SUFFIX}"); }
PRINT_PLIST_AWK+=	/^man\/man[0-9]\/.*${RUBY_SUFFIX}.[0-9]$$/ \
			{ sub(/${RUBY_SUFFIX}\./, "$${RUBY_SUFFIX}."); }

# supporting scripts
UPDATE_GEMSPEC=		../../lang/ruby/files/update-gemspec.rb

.endif # _RUBY_MK
