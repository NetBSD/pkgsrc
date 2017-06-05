# $NetBSD: buildlink3.mk,v 1.21 2017/06/05 14:22:26 ryoon Exp $

BUILDLINK_TREE+=	p5-DBI

.if !defined(P5_DBI_BUILDLINK3_MK)
P5_DBI_BUILDLINK3_MK:=

.  include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_API_DEPENDS.p5-DBI+=	p5-DBI>=1.612
BUILDLINK_ABI_DEPENDS.p5-DBI?=	p5-DBI>=1.636nb3
BUILDLINK_PKGSRCDIR.p5-DBI?=	../../databases/p5-DBI
BUILDLINK_INCDIRS.p5-DBI?=	${PERL5_SUB_INSTALLVENDORARCH}/auto/DBI

# We want all of the arch-dependent DBI files.
BUILDLINK_CONTENTS_FILTER.p5-DBI?=	${GREP} '/auto/DBI/'

.include "../../lang/perl5/buildlink3.mk"
.endif # P5_DBI_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-DBI
