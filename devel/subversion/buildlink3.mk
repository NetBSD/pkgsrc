# $NetBSD: buildlink3.mk,v 1.1 2004/03/08 00:15:53 minskim Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SUBVERSION_BASE_BUILDLINK3_MK:=	${SUBVERSION_BASE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	subversion-base
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsubversion-base}
BUILDLINK_PACKAGES+=	subversion-base

.if !empty(SUBVERSION_BASE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.subversion-base+=	subversion-base>=${SVNVER}
BUILDLINK_PKGSRCDIR.subversion-base?=	../../devel/subversion-base

BUILDLINK_FILES.subversion-base+=	bin/svn-config

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/apr/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"

.include "../../devel/subversion/Makefile.version"

.endif	# SUBVERSION_BASE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
