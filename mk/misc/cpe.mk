# $NetBSD: cpe.mk,v 1.1 2023/01/02 21:17:53 wiz Exp $
# Derived from: FreeBSD MK/Uses/cpe.mk (3e1b730be0f27, 2014-07-26)
# 
# This Makefile fragment includes CPE information into packages based on the
# CPE 2.3 formatting string. Additional information could be found on the
# official NIST documentation:
#
# https://csrc.nist.gov/projects/security-content-automation-protocol/specifications/cpe
#
# User-settable variables:
#
# (none)
#
# Package-settable variables:
#
# CPE_PART
#	This is sometimes referred as "type" of CPE. Character describing the
#	type. Could be "a" for application, "h" for hardware and "o" for
#	operating system.
#	Default: "a"
#
# CPE_VENDOR
#	Should describe or identify the organisation that created the product.
#	Default: ${CPE_PRODUCT} (below)
#
# CPE_PRODUCT
#	Name of the system/package or component. Should not contains any
#	special characters. On applications CPE_VENDOR and CPE_PRODUCT may be
#	identical.
#	Default: ${PKGBASE}
#
# CPE_VERSION
#	The version of the system/package or component.
#	Default: ${PKGVERSION_NOREV}
#
# CPE_UPDATE
#	Used for updates, service pack information or sometimes minor versions.
#	Most often left blank.
#	Default: empty
#
# CPE_EDITION
#	Further granularity describing the build of the system/package or
#	component, beyond version.
#	Default: empty
#
# CPE_LANG
#	A valid language tag as defined by IETF RFC 4646. Not relevant for
#	pkgsrc at the moment.
#	Default: empty
#
# CPE_SW_EDITION
#	Characterise how the product is tailored to a particular market or
#	class of end users.
#	Default: empty
#
# CPE_TARGET_SW
#	Describe the software computing environment within which the product
#	operates.
#	Default: operating system (${OPSYS}) and version (${OS_VERSION})
#
# CPE_TARGET_HW
#	Instruction set architecture (e.g. x86) on which the product being
#	described or identified by the WFN operates. 
#	Default: x86 for i386, x64 for amd64, otherwise ${MACHINE_ARCH}
#
# CPE_OTHER
#	Any other general descriptive or identifying information. Used for
#	PKGREVISION in pkgsrc.
#	Default: ${PKGREVISION} if exists
#
#
# Variables defined by this file:
# 
# CPE_URI
#	The CPE URI uniquely identifies a device or program by its vendor,
#	product name, version, revision. Based on the above variables.
#
# Keywords: cpe

.if !defined(CPE_MK)
CPE_MK=			# defined

CPE_PART?=		a
CPE_PRODUCT?=		${PKGBASE:Q}
CPE_VENDOR?=		${CPE_PRODUCT}
CPE_VERSION?=		${PKGVERSION_NOREV}
CPE_UPDATE?=
CPE_EDITION?=
CPE_LANG?=
CPE_SW_EDITION?=
CPE_TARGET_SW?=		${OPSYS:tl}${OS_VERSION:C/\..*//}
CPE_TARGET_HW?=		${MACHINE_ARCH:S/i386/x86/:S/amd64/x64/}
CPE_OTHER?=		${PKGREVISION}

_CPE_STR=		cpe:2.3:${CPE_PART}:${CPE_VENDOR}:${CPE_PRODUCT}:${CPE_VERSION}:${CPE_UPDATE}:${CPE_EDITION}:${CPE_LANG}:${CPE_SW_EDITION}:${CPE_TARGET_SW}:${CPE_TARGET_HW}:${CPE_OTHER}

CPE_URI?=		${_CPE_STR:C/:+$//}

BUILD_DEFS+=		CPE_URI
.endif
