# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/03 15:11:23 epg Exp $

.if !defined(SWIG_PERL_BUILDLINK2_MK)
SWIG_PERL_BUILDLINK2_MK=		#defined

BUILDLINK_PACKAGES+=			swig-perl
BUILDLINK_DEPENDS.swig-perl?=		swig-perl>=${SWIG_VERSION}
BUILDLINK_PKGSRCDIR.swig-perl?=		../../devel/swig-perl

EVAL_PREFIX+=				BUILDLINK_PREFIX.swig-perl=swig-perl
BUILDLINK_PREFIX.swig-perl_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.swig-perl+=		lib/libswigpl.*

.include "../../lang/perl5/buildlink2.mk"

.include "../../devel/swig-build/Makefile.version"

BUILDLINK_TARGETS+=			swig-perl-buildlink

swig-perl-buildlink: _BUILDLINK_USE

.endif	# SWIG_PERL_BUILDLINK2_MK
