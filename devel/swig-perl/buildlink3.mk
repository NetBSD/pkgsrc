# $NetBSD: buildlink3.mk,v 1.1 2004/03/08 00:15:53 minskim Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SWIG_PERL_BUILDLINK3_MK:=	${SWIG_PERL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	swig-perl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nswig-perl}
BUILDLINK_PACKAGES+=	swig-perl

.if !empty(SWIG_PERL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.swig-perl+=	swig-perl>=${SWIG_VERSION}
BUILDLINK_PKGSRCDIR.swig-perl?=	../../devel/swig-perl

.include "../../lang/perl5/buildlink3.mk"

.include "../../devel/swig-build/Makefile.version"

.endif	# SWIG_PERL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
