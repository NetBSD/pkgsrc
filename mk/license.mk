# $NetBSD: license.mk,v 1.4 2007/07/20 13:05:28 gdt Exp $
#
# Note: This file is in draft state and not yet actively used.
#
# This file handles everything about the LICENSE variable. It is
# included automatically by bsd.pkg.mk.
#
# XXX: Some of this content arguably belongs in the pkgsrc guide
# instead.
#
# === User-settable variables ===
#
# ACCEPTABLE_LICENSES
#	If a package declares a license and that license is not a
#	member of the list defined by this variable, pkgsrc will
#	refuse to build the package.
#
#	XXX: pkg_install should also check LICENSE and decline to
#	install if it is not in ACCEPTABLE_LICENSES.
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
#	The license of the package.
#
#	When the package has multiple licenses, there are many different
#	cases. Some packages use an OR-combination, while others use an
#	AND-combination. Currently, pkgsrc can only handle a single
#	license per package. For now, add a description of the licensing
#	to ../doc/TODO, section "Licenses of packages".  Note that in
#	such cases, one can place the text of both licenses in
#	licenses/foo-license and reference it.
#
#	Every package should specify its license.  (Prior to July 2007,
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
#	The list of licenses that before July, 2007 did not require
#	tagging because they were Open Source or Free.  The intent is
#	to make it contain licenses that are Open Source or Free and
#	not controversial, so as to provide a default that almost all
#	people find acceptable.  (Many people will want to add more
#	licenses to ACCEPTABLE_LICENSES; the point is to have a
#	default that very few people want to shrink.)
#
# === See also ===
#
#	../doc/TODO, section "Licenses of packages"
#

.if defined(AFTER_2007Q3) && !defined(LICENSE)
PKG_FAIL_REASON+=	"[license.mk] Every package must define a license"
LICENSE?=		unknown
.endif

# TODO: Determine whether GPLv3 should be included (and therefore if
# there should be a "widely accepted" test in addition to open
# source/free).  Perhaps wait until OSI decides whether or not to
# approve GPLv3 as open source.

# This list is not complete.  Free and Open Source licenses should be
# added to the list as they are added to pkgsrc.

DEFAULT_ACCEPTABLE_LICENSES= \
	public-domain \
	gnu-gpl-v2 gnu-lgpl-v2 \
	original-bsd modified-bsd \
	x11 \
	apache-2.0 \
	cddl-1.0
