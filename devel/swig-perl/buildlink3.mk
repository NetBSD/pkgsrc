# $NetBSD: buildlink3.mk,v 1.3 2004/10/03 00:13:33 tv Exp $

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
BUILDLINK_RECOMMENDED.swig-perl+=	swig-perl>=1.3.19nb1
BUILDLINK_PKGSRCDIR.swig-perl?=	../../devel/swig-perl
.endif	# SWIG_PERL_BUILDLINK3_MK

.include "../../lang/perl5/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
