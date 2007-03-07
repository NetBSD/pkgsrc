# $NetBSD: krb5.buildlink3.mk,v 1.11 2007/03/07 10:42:30 rillig Exp $
#
# This Makefile fragment is meant to be included by packages that
# require a Kerberos 5 implementation.  krb5.buildlink3.mk will:
#
#	* set KRB5BASE to the base directory of the Kerberos 5 files;
#	* set KRB5_TYPE to the Kerberos 5 implementation used.
#
# User-settable variables:
#
# KRB5_DEFAULT
#	The default Kerberos 5 implementation to use.
#
#	Possible values: heimdal mit-krb5
#
# Package-settable variables:
#
# KRB5_ACCEPTED
#	The list of Kerberos 5 implementations that can be used by the
#	package.
#
#	Possible values: (see KRB5_DEFAULT)
#
# Keywords: kerberos heimdal krb krb5 mit-krb5

KRB5_BUILDLINK3_MK:=	${KRB5_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(KRB5_BUILDLINK3_MK:M+)
.if ${OPSYS} != Darwin
KRB5_DEFAULT?=	heimdal
.else
KRB5_DEFAULT?=	mit-krb5
.endif
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

BUILD_DEFS+=		KRB5_DEFAULT
BUILD_DEFS_EFFECTS+=	KRB5BASE KRB5_TYPE

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
