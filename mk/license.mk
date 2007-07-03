# $NetBSD: license.mk,v 1.1 2007/07/03 05:08:12 rillig Exp $
#
# Note: This file is in draft state and not yet actively used.
#
# This file handles everything about the LICENSE variable. It is
# included automatically by bsd.pkg.mk.
#
# === User-settable variables ===
#
# ACCEPTABLE_LICENSES
#	The list of licenses that the package builder is willing to
#	accept.
#
#	XXX: We need a similar feature for the _user_ of the packages.
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
#	to ../doc/TODO, section "Licenses of packages".
#
#	Every package needs to specify its license, even if it is open
#	source or free software.
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
#	The list of all licenses that did not require explicit tagging in
#	pkgsrc packages before 2007Q3.
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
