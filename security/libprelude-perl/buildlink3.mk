# $NetBSD: buildlink3.mk,v 1.2 2018/08/22 09:42:52 wiz Exp $

BUILDLINK_TREE+=	libprelude-perl

.if !defined(LIBPRELUDE_PERL_BUILDLINK3_MK)
LIBPRELUDE_PERL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libprelude-perl+=	libprelude-perl>=0.9.24
BUILDLINK_ABI_DEPENDS.libprelude-perl?=	libprelude-perl>=0.9.24.1nb16
BUILDLINK_PKGSRCDIR.libprelude-perl?=	../../security/libprelude-perl
.endif	# LIBPRELUDE_PERL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libprelude-perl
