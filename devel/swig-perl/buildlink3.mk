# $NetBSD: buildlink3.mk,v 1.2 2004/03/18 09:12:11 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SWIG_PERL_BUILDLINK3_MK:=	${SWIG_PERL_BUILDLINK3_MK}+

.include "../../devel/swig-build/Makefile.version"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	swig-perl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nswig-perl}
BUILDLINK_PACKAGES+=	swig-perl

.if !empty(SWIG_PERL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.swig-perl+=	swig-perl>=${SWIG_VERSION}
BUILDLINK_PKGSRCDIR.swig-perl?=	../../devel/swig-perl
.endif	# SWIG_PERL_BUILDLINK3_MK

.include "../../lang/perl5/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
