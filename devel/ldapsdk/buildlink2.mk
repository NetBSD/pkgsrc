# $NetBSD: buildlink2.mk,v 1.1 2002/10/20 21:48:17 seb Exp $
#
# This Makefile fragment is included by packages that use ldapsdk.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(LDAPSDK_BUILDLINK2_MK)
LDAPSDK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			ldapsdk
BUILDLINK_DEPENDS.ldapsdk?=		ldapsdk>=12311998
BUILDLINK_PKGSRCDIR.ldapsdk?=		../../devel/ldapsdk

EVAL_PREFIX+=	BUILDLINK_PREFIX.ldapsdk=ldapsdk
BUILDLINK_PREFIX.ldapsdk_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ldapsdk+=	include/disptmpl.h
BUILDLINK_FILES.ldapsdk+=	include/lber.h
BUILDLINK_FILES.ldapsdk+=	include/ldap.h
BUILDLINK_FILES.ldapsdk+=	include/srchpref.h
BUILDLINK_FILES.ldapsdk+=	lib/liblber.*
BUILDLINK_FILES.ldapsdk+=	lib/libldap.*

BUILDLINK_TARGETS+=	ldapsdk-buildlink

ldapsdk-buildlink: _BUILDLINK_USE

.endif	# LDAPSDK_BUILDLINK2_MK
