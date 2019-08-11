# $NetBSD: buildlink3.mk,v 1.3 2019/08/11 13:17:49 wiz Exp $

BUILDLINK_TREE+=	libprelude-perl

.if !defined(LIBPRELUDE_PERL_BUILDLINK3_MK)
LIBPRELUDE_PERL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libprelude-perl+=	libprelude-perl>=0.9.24
BUILDLINK_ABI_DEPENDS.libprelude-perl?=	libprelude-perl>=0.9.24.1nb18
BUILDLINK_PKGSRCDIR.libprelude-perl?=	../../security/libprelude-perl
.endif	# LIBPRELUDE_PERL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libprelude-perl
