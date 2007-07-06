# $NetBSD: license.mk,v 1.3 2007/07/06 01:22:40 rillig Exp $
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
#	The common licenses are collected in the licenses/ subdirectory
#	of pkgsrc. Additionally, the following licenses are valid:
#
#	* GPL2: The GNU General Public License, Version 2
#	* LGPL2: The GNU Library General Public License, Version 2
#	* BSD-3: The license from UCB without the advertising clause
#	* BSD-4: The license from UCB including the advertising clause
#	* Apache-2.0: Apache License, Version 2.0
#	* CDDL: Common Development and Distribution License, Version 1.0
#
#	TODO:
#	* GPL3
#
# === Predefined variables ===
#
# DEFAULT_ACCEPTABLE_LICENSES
#	The list of licenses that before July,
#	2007 did not require tagging because they were Open Source or
#	Free.  The intent is to make it contain licenses that are Open
#	Source or Free and not controversial, so as to provide a
#	default that is pleasing to a large number of people.
#
# === See also ===
#
#	../doc/TODO, section "Licenses of packages"
#

.if defined(AFTER_2007Q3) && !defined(LICENSE)
PKG_FAIL_REASON+=	"[license.mk] Every package must define a license"
LICENSE?=		unknown
.endif

DEFAULT_ACCEPTABLE_LICENSES=	GPL2 LGPL2 BSD-3 BSD-4 Apache-2.0 CDDL
