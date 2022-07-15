# $NetBSD: license.mk,v 1.115 2022/07/15 00:51:13 gutteridge Exp $
#
# This file handles everything about the LICENSE variable. It is
# included automatically by bsd.pkg.mk.
#
# XXX There should be one place to set the default list and for users
# to set the ACCEPTABLE_LICENSES list, used by both source builds and
# binary installs.
#
# XXX: Some of this content arguably belongs in the pkgsrc guide
# instead.
#
# User-settable variables:
#
# ACCEPTABLE_LICENSES
#
#	If a package declares a license and that license is not a
#	member of the list defined by this variable, pkgsrc will not
#	build the package and instead print an error message.
#	(pkg_install has code to behave the same way, but it is not
#	yet turned on.)
#
#	To include the default licenses, you can use the += operator
#	in mk.conf. To override it, use the plain = operator.
#
#	Default value: ${DEFAULT_ACCEPTABLE_LICENSES}
#
# Package-settable variables:
#
# LICENSE
#
#	The license of the package.
#
#	Dual licenses can be specified with OR expressions:
#	LICENSE=	license1 OR license2
#
#	If more than one license applies at the same time, AND expressions
#	can be used:
#	LICENSE=	license1 AND license2
#
#	Expressions can be nested if necessary:
#	LICENSE=	(license1 AND license2) OR license3
#	Parenthesis are required when mixing AND and OR.
#
#	Every package should specify its license.
#
#	Licenses are collected in the licenses/ subdirectory of
#	pkgsrc.  For open source license, we generally use the same
#	names as either the Open Source Initiative or the Free
#	Software Foundation, choosing a name to reduce confusion.
#	Open Source and Free licenses do not have a -license suffix,
#	and non-Free licenses do.
#
#	http://opensource.org/licenses/category
#	http://www.gnu.org/licenses/license-list.html
#
# === Predefined variables ===
#
# DEFAULT_ACCEPTABLE_LICENSES
#	The list of licenses that will be the default value of
#	ACCEPTABLE_LICENSES.  Adapting the longstanding policy of Open
#	Source or Free licenses not requiring tags, it should contain
#	all licenses that are definitively Free or Open Source --
#	except those specifically excluded by the TNF board -- so as
#	to provide the most expansive default that almost all people
#	find acceptable.  (Many people will want to add more licenses
#	to ACCEPTABLE_LICENSES; the point is to have a default that
#	very few people want to shrink.)
#
#	Licenses approved by FSF as Free and by OSI as Open Source
#	will be added by default, without annotation, as these
#	organizations publish lists of approved licenses.
#
#	Licenses approved by Debian as meeting the Debian Free
#	Software Guidelines will also be added by default.  They
#	should be in a second section with a comment about each one,
#	because Debian does not publish an approved license list and
#	approval must be inferred from inclusion in main.
#
#	The board of The NetBSD Foundation is the final arbiter of
#	which licenses may be in DEFAULT_ACCEPTABLE_LICENSES.  As an
#	exception to the above policy on treating Free, Open Source,
#	and DFSG licenses as acceptable, the board has decided that
#	licenses that trigger obligations from use (rather than
#	redistribution), such as the Affero GPL, should not be in
#	DEFAULT_ACCEPTABLE_LICENSES.
#
#	Licenses not formally approved as Free or Open Source may be
#	added if they have terms that would 1) obviously be approved
#	by FSF or OSI if the effort were made and 2) obviously not
#	trigger the above issue with AGPL-type licenses.  Such license
#	names will be in an additional section and have a comment near
#	them in the assignment to DEFAULT_ACCEPTABLE_LICENSES.
#
#	The pkg_install sources also have a
#	DEFAULT_ACCEPTABLE_LICENSES list, and that should be updated
#	to match the list here.  See
#	pkgsrc/pkgtools/pkg_install/files/lib/license.c
#
# === See also ===
#
#	../doc/TODO, section "Licenses of packages"
#
# Keywords: licence license
#

# The convention is that Free and Open Source licenses do not have a
# -license suffix, and non-Free licenses end in -license.  Thus,
# licenses in DEFAULT_ACCEPTABLE_LICENSES should not end in -license.
#
# First, we set DEFAULT_ACCEPTABLE_LICENSES to the set of licenses
# formally approved as Free Software by FSF or Open Source by OSI,
# except that we exclude the AGPL (clearly a Free license), following
# the decision of the board of TNF.
DEFAULT_ACCEPTABLE_LICENSES= \
	afl-3.0 \
	apache-1.1 apache-2.0 \
	arphic-public \
	artistic artistic-2.0 \
	beer-ware \
	boost-license \
	cc-by-sa-v3.0 \
	cc-by-sa-v4.0 \
	cc-by-v4.0 \
	cc0-1.0-universal \
	cddl-1.0 \
	cecill-2.1 \
	cecill-b-v1 \
	cpl-1.0 \
	epl-v1.0 \
	eupl-v1.1 \
	gfsl \
	gnu-fdl-v1.1 gnu-fdl-v1.2 gnu-fdl-v1.3 \
	gnu-gpl-v1 \
	gnu-gpl-v2 gnu-lgpl-v2 gnu-lgpl-v2.1 \
	gnu-gpl-v3 gnu-lgpl-v3 \
	happy \
	hpnd \
	ijg \
	info-zip \
	ipafont \
	ipl-1.0 \
	isc \
	lppl-1.0 lppl-1.2 lppl-1.3c \
	lucent \
	miros \
	mit \
	mpl-1.0 mpl-1.1 mpl-2.0 \
	mplusfont \
	ms-pl \
	odbl-v1 \
	ofl-v1.0 ofl-v1.1 \
	openssl \
	original-bsd modified-bsd 2-clause-bsd 0-clause-bsd \
	osl \
	paratype \
	php \
	png-license \
	postgresql-license \
	public-domain \
	python-software-foundation \
	qpl-v1.0 \
	sgi-free-software-b-v2.0 \
	sissl-1.1 \
	sleepycat-public \
	unicode \
	unlicense \
	vera-ttf-license \
	w3c \
	x11 \
	zlib \
	zpl-2.0 zpl-2.1 \
	zsh

# The following licenses meet the DFSG (but are not formally approved
# by FSF/OSI) as evidenced by inclusion in Debian main.
#
# used in https://sources.debian.org/copyright/license/python-biopython/
DEFAULT_ACCEPTABLE_LICENSES+=	biopython
# \todo reference to package
DEFAULT_ACCEPTABLE_LICENSES+=	happy
# used in https://sources.debian.org/copyright/license/lsof/
DEFAULT_ACCEPTABLE_LICENSES+=	purdue

# The following licenses are included based on it being obvious they
# would be approved.
#
# derived from BSD
DEFAULT_ACCEPTABLE_LICENSES+=	info-zip
# Derived from MIT, with an advertising clause added (and previously
# included in Debian main as such).
DEFAULT_ACCEPTABLE_LICENSES+=	enlightenment16

# The following licenses do not currently meet our standards for
# inclusion.

# Mostly in line with Free Software principles and typefaces can not be
# sold by themselves.
DEFAULT_ACCEPTABLE_LICENSES+=	vera-ttf-license

##### Variant spellings

.if defined(ACCEPTABLE_LICENCES) && !defined(ACCEPTABLE_LICENSES)
ACCEPTABLE_LICENSES=	${ACCEPTABLE_LICENCES}
.endif

.if !defined(LICENSE)
.  if ${PKG_DEVELOPER:Uno} != "no"
WARNINGS+=		"[license.mk] Every package should define a LICENSE."
.  endif

.else

.if defined(_ACCEPTABLE)
WARNINGS+=	"Deprecated variable _ACCEPTABLE found, use SKIP_LICENSE_CHECK=yes"
SKIP_LICENSE_CHECK=	yes
.endif

SKIP_LICENSE_CHECK?=	no

.if !empty(SKIP_LICENSE_CHECK:M[Yy][Ee][Ss])
_ACCEPTABLE_LICENSE=	skipped
.else
_ACCEPTABLE_LICENSE!=	\
	${PKGSRC_SETENV} PKGSRC_ACCEPTABLE_LICENSES=${ACCEPTABLE_LICENSES:Q} \
	PKGSRC_DEFAULT_ACCEPTABLE_LICENSES=${DEFAULT_ACCEPTABLE_LICENSES:Q} \
	${PKG_ADMIN} check-license ${LICENSE:Q} || echo failure
.endif

.if ${_ACCEPTABLE_LICENSE} == "no"
.  if defined(MAKECONF)
_MAKE_CONF?=	${MAKECONF}
.  elif ${OPSYS} == "NetBSD" && ${MAKE} == "/usr/bin/make"
_MAKE_CONF?=	/etc/mk.conf
.  else
_MAKE_CONF?=	${PREFIX}/etc/mk.conf
.endif
.  if ${OPSYS} == "NetBSD" && ${PKG_TOOLS_BIN} == "/usr/sbin"
_PKG_INSTALL_CONF?=	/etc/pkg_install.conf
.  else
_PKG_INSTALL_CONF?=	${PREFIX}/etc/pkg_install.conf
.endif

.  if empty(LICENSE:MAND) && empty(LICENSE:MOR) && empty(LICENSE:M*[()]*)
PKG_FAIL_REASON+= "${PKGNAME} has an unacceptable license condition: " \
    "    "${LICENSE:Q} \
    "You can mark the license \`\`${LICENSE}'' as acceptable by adding" \
    "    ACCEPTABLE_LICENSES+= ${LICENSE}" \
    "to ${_MAKE_CONF} or by adding" \
    "    ACCEPTABLE_LICENSES= ${LICENSE}" \
    "to ${_PKG_INSTALL_CONF}."
PKG_FAIL_REASON+= "The following command will show you the license text:" \
    "    ${MAKE} show-license"
.  else
PKG_FAIL_REASON+= "${PKGNAME} has an unacceptable license condition: " \
    "    "${LICENSE:Q} \
    "" \
    "Check that you have accepted all necessary licenses." \
    "You can mark a particular license \`\`foo'' as acceptable by adding" \
    "    ACCEPTABLE_LICENSES+= foo" \
    "to ${_MAKE_CONF} or by adding" \
    "    ACCEPTABLE_LICENSES= foo" \
    "to ${_PKG_INSTALL_CONF}."
.  endif

.elif ${_ACCEPTABLE_LICENSE} == "failure"
PKG_FAIL_REASON+= "License conditions for ${PKGNAME} could not be evaluated"
.elif ${_ACCEPTABLE_LICENSE} == "outdated"
PKG_FAIL_REASON+= \
    "Your pkg_install is too old to evaluate license conditions" \
    "You can bypass this check by setting SKIP_LICENSE_CHECK=yes"
.endif

.endif

# guess-license:
#	Extracts the current package and tries to guess its license.
#	This is useful for package developers.
#
# Keywords: license
guess-license: .PHONY
	@# Running "make extract" would fetch and build the dependencies
	${RUN} [ -d ${WRKSRC} ] \
	|| ALLOW_VULNERABLE_PACKAGES=yes ${MAKE} makedirs fetch pre-extract do-extract

	${RUN} \
	\
	type ninka > /dev/null 2>&1 || { \
		${ERROR_MSG} "To guess the license, devel/ninka must be installed."; \
		${FAIL_MSG} "Run '(cd ../../devel/ninka && ${MAKE} install)' to install it."; \
	}; \
	\
	${PHASE_MSG} "Guessing licenses for ${PKGNAME}"; \
	\
	: "Note that ninka can only handle one file at a time; therefore the slow loop below."; \
	cd ${WRKDIR} \
	&& ${FIND} ./* -type f -print \
	| while read fname; do ninka "$$fname"; done \
	| ${AWK} -F ';' '{ print $$2 }' \
	| LC_ALL=C ${SORT} | uniq -c | LC_ALL=C ${SORT} -nr \
	| ${AWK} 'BEGIN { printf("%5s   %s\n", "Files", "License") } { printf("%5d   %s\n", $$1, $$2); }'

_VARGROUPS+=		license
_USER_VARS.license=	ACCEPTABLE_LICENSES SKIP_LICENSE_CHECK
_PKG_VARS.license=	LICENSE
_SYS_VARS.license=	DEFAULT_ACCEPTABLE_LICENSES
_SORTED_VARS.license=	*_LICENSES SKIP_*
