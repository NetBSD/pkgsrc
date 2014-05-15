# $NetBSD: license.mk,v 1.63 2014/05/15 09:59:09 wiz Exp $
#
# This file handles everything about the LICENSE variable. It is
# included automatically by bsd.pkg.mk.
#
# XXX There should be one place to set the default list and for users
# to set the ACCEPTABLE_LICENSES list, used by both source builds and
# binary installs#
#
# XXX: Some of this content arguably belongs in the pkgsrc guide
# instead.
#
# === User-settable variables ===
#
# ACCEPTABLE_LICENSES
#
#	If a package declares a license and that license is not a
#	member of the list defined by this variable, pkgsrc will not
#	build the package and instead print an error message.
#	(pkg_install has code to behave the same way, but it is not
#	yet turned on.)
#
#	XXX: Perhaps there should be some mechanism to prevent running
#	programs that are part of packages that declare LICENSEs that
#	are not in ACCEPTABLE_LICENSES or some per-user variable.
#	This is surely controversial and requires discussion.
#
#	To include the default licenses, you can use the += operator
#	in mk.conf. To override it, use the plain = operator.
#
#	Default value: ${DEFAULT_ACCEPTABLE_LICENSES}
#
# === Package-settable variables ===
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
#	Every package should specify its license.  (Prior to early 2009,
#	Open Source and Free software did not have license tags.)
#
#	Licenses are collected in the licenses/ subdirectory of
#	pkgsrc.  For open source license, we generally use the same
#	names as either the Open Source Initiative or the Free
#	Software Foundation, choosing a name to reduce confusion.
#	Open source and free licenses do not have a -license suffix,
#	and non-free licenses do.
#
#	http://opensource.org/licenses/category
#	http://www.fsf.org/licensing/licenses/index_html
#
# === Predefined variables ===
#
# DEFAULT_ACCEPTABLE_LICENSES
#	The list of licenses that will be the default value of
#	ACCEPTABLE_LICENSES.  Adapting the longstanding policy of Open
#	Source or Free licenses not requiring tags, it should contain
#	almost all licenses that are Open Source or Free, so as to provide
#	the most expansive default that almost all people find
#	acceptable.  (Many people will want to add more licenses to
#	ACCEPTABLE_LICENSES; the point is to have a default that very
#	few people want to shrink.)
#
#	As an exception to the Open Source or Free policy, the board
#	of The NetBSD Foundation has decided that licenses that
#	trigger obligations from use (rather than redistribution),
#	such as the Affero GPL, should not be in
#	DEFAULT_ACCEPTABLE_LICENSES.
#
#	Licenses not formally approved as Free or Open Source may be
#	added if they have terms that would obviously be approved if
#	the effort were made.  Such license names will have a comment
#	near them in the assignment to DEFAULT_ACCEPTABLE_LICENSES.
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

# This list is not complete.  Free and Open Source licenses should be
# added to the list as they are added to pkgsrc.

# The convention is that Free or Open Source licenses do not have a
# -license suffix, and nonfree licenses end in -license.

DEFAULT_ACCEPTABLE_LICENSES= \
	apache-1.1 apache-2.0 \
	arphic-public \
	artistic artistic-2.0 \
	boost-license \
	cc-by-sa-v3.0 \
	cc0-1.0-universal \
	cddl-1.0 \
	cecill-2.1 \
	cpl-1.0 \
	epl-v1.0 \
	eupl-v1.1 \
	gnu-fdl-v1.1 gnu-fdl-v1.2 gnu-fdl-v1.3 \
	gnu-gpl-v1 \
	gnu-gpl-v2 gnu-lgpl-v2 gnu-lgpl-v2.1 \
	gnu-gpl-v3 gnu-lgpl-v3 \
	ibm-public-license-1.0 \
	ipafont \
	isc \
	lppl-1.3c \
	lucent \
	miros \
	mit \
	mpl-1.0 mpl-1.1 mpl-2.0 \
	mplusfont \
	ofl-v1.0 ofl-v1.1 \
	openssl \
	original-bsd modified-bsd 2-clause-bsd \
	php \
	png-license \
	postgresql-license \
	public-domain \
	python-software-foundation \
	qpl-v1.0 \
	sgi-free-software-b-v2.0 \
	sleepycat-public \
	unlicense \
	x11 \
	zlib \
	zpl

# not approved by OSI, derived from BSD
DEFAULT_ACCEPTABLE_LICENSES+=	info-zip

##### Variant spellings

.if defined(ACCEPTABLE_LICENCES) && !defined(ACCEPTABLE_LICENSES)
ACCEPTABLE_LICENSES=	${ACCEPTABLE_LICENCES}
.endif

.if !defined(LICENSE)
.  if defined(PKG_DEVELOPER) && ${PKG_DEVELOPER} != "no"
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
    if test `${PKG_ADMIN} -V` -lt 20090528; then \
	echo outdated; \
    else \
	${PKGSRC_SETENV} PKGSRC_ACCEPTABLE_LICENSES=${ACCEPTABLE_LICENSES:Q} \
	PKGSRC_DEFAULT_ACCEPTABLE_LICENSES=${DEFAULT_ACCEPTABLE_LICENSES:Q} \
	${PKG_ADMIN} check-license ${LICENSE:Q} || echo failure; \
    fi
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
