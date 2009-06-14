# $NetBSD: license.mk,v 1.24 2009/06/14 15:15:24 joerg Exp $
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
#	Sometimes licensing is other than a single text file.  See
#	doc/TODO for discussion of how to handle packages with dual
#	licensing (a choice) or where multiple licenses apply
#	simultaneously.
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
#	all licenses that are Open Source or Free, so as to provide
#	the most expansive default that almost all people find
#	acceptable.  (Many people will want to add more licenses to
#	ACCEPTABLE_LICENSES; the point is to have a default that very
#	few people want to shrink.)
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

# XXX open-font-license should perhaps be changed to open-font

DEFAULT_ACCEPTABLE_LICENSES= \
	public-domain \
	gnu-fdl-v1.1 gnu-fdl-v1.2 gnu-fdl-v1.3 \
	gnu-gpl-v2 gnu-lgpl-v2 gnu-lgpl-v2.1 \
	gnu-gpl-v3 gnu-lgpl-v3 \
	original-bsd modified-bsd \
	x11 mit miros \
	apache-1.1 apache-2.0 \
	artistic artistic-2.0 \
	cddl-1.0 \
	cpl-1.0 \
	open-font-license

##### Variant spellings

.if defined(ACCEPTABLE_LICENCES) && !defined(ACCEPTABLE_LICENSES)
ACCEPTABLE_LICENSES=	${ACCEPTABLE_LICENCES}
.endif

.if !defined(LICENSE)
.  if defined(PKG_DEVELOPER)
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
_ACCEPTABLE_LICENSE!=	${SETENV} \
    PKGSRC_ACCEPTABLE_LICENSES=${ACCEPTABLE_LICENSES:Q} \
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

PKG_FAIL_REASON+= "${PKGNAME} has an unacceptable license condition: " \
    "    "${LICENSE:Q} \
    "You can mark the license \`\`license'' as acceptable by adding" \
    "    ACCEPTABLE_LICENSES+= license" \
    "to ${_MAKE_CONF} or by adding" \
    "    ACCEPTABLE_LICENSES= license" \
    "to ${_PKG_INSTALL_CONF}."
.  if empty(LICENSE:M*[A-Z()])
PKG_FAIL_REASON+= "The following command will show you the license text:" \
    "    ${MAKE} show-license"
.  endif

.elif ${_ACCEPTABLE_LICENSE} == "failure"
PKG_FAIL_REASON+= "License conditions for ${PKGNAME} could not be evaluated"
.endif

.endif
