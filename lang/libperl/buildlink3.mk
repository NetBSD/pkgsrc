# $NetBSD: buildlink3.mk,v 1.12 2005/05/18 22:42:07 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBPERL_BUILDLINK3_MK:=	${LIBPERL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libperl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibperl}
BUILDLINK_PACKAGES+=	libperl

.if !empty(LIBPERL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libperl+=	{libperl>=${PERL5_REQD},perl{,-thread}>=5.8.0}
BUILDLINK_PKGSRCDIR.libperl?=	../../lang/perl58
.endif	# LIBPERL_BUILDLINK3_MK

.include "../../lang/perl5/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
