# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/08/23 19:05:00 hasso Exp $

BUILDLINK_TREE+=	libprelude-perl

.if !defined(LIBPRELUDE_PERL_BUILDLINK3_MK)
LIBPRELUDE_PERL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libprelude-perl+=	libprelude-perl>=0.9.24
BUILDLINK_PKGSRCDIR.libprelude-perl?=	../../security/libprelude-perl
.endif	# LIBPRELUDE_PERL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libprelude-perl
