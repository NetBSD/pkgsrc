# $NetBSD: krb5.buildlink3.mk,v 1.7.6.1 2005/01/10 16:15:25 tv Exp $
#
# This Makefile fragment is meant to be included by packages that
# require a Kerberos 5 implementation.  krb5.buildlink3.mk will:
#
#	* set KRB5BASE to the base directory of the Kerberos 5 files;
#	* set KRB5_TYPE to the Kerberos 5 implementation used.
#
# There are two variables that can be used to tweak the selection of
# the Kerberos 5 implementation:
#
# KRB5_DEFAULT is a user-settable variable whose value is the default
#	Kerberos 5 implementation to use.
#
# KRB5_ACCEPTED is a package-settable list of Kerberos 5 implementations
#	that may be used by the package.

KRB5_BUILDLINK3_MK:=	${KRB5_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(KRB5_BUILDLINK3_MK:M+)
KRB5_DEFAULT?=	heimdal
KRB5_ACCEPTED?=	${_KRB5_PKGS}

# This is an exhaustive list of all of the Kerberos 5 implementations
# that may be used with krb5.buildlink3.mk, in order of precedence.
#
_KRB5_PKGS?=	heimdal mit-krb5

_KRB5_DEFAULT=	${KRB5_DEFAULT}
_KRB5_ACCEPTED=	${KRB5_ACCEPTED}

_KRB5_TYPE?=	${_KRB5_DEFAULT}

.  if !empty(_KRB5_ACCEPTED:M${_KRB5_TYPE})
KRB5_TYPE=	${_KRB5_TYPE}
.  else
KRB5_TYPE=	none
.  endif
KRB5BASE=	${BUILDLINK_PREFIX.${KRB5_TYPE}}

BUILD_DEFS+=	KRB5_TYPE
BUILD_DEFS+=	KRB5BASE

# Packages that use Kerberos are automatically categorized as restricted
# packages.
#
CRYPTO+=	uses Kerberos encryption code

.endif	# KRB5_BUILDLINK3_MK

.if ${KRB5_TYPE} == "none"
PKG_FAIL_REASON=	\
	"${_KRB5_TYPE} is not an acceptable Kerberos 5 type for ${PKGNAME}."
.elif ${KRB5_TYPE} == "heimdal"
.  include "../../security/heimdal/buildlink3.mk"
.elif ${KRB5_TYPE} == "mit-krb5"
.  include "../../security/mit-krb5/buildlink3.mk"
.endif
