# $NetBSD: buildlink2.mk,v 1.2 2003/07/13 13:53:31 wiz Exp $
#
# This Makefile fragment is included by packages that use aspell.
#

.if !defined(ASPELL_BUILDLINK2_MK)
ASPELL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			aspell
BUILDLINK_DEPENDS.aspell?=		aspell>=0.50.3nb2
BUILDLINK_PKGSRCDIR.aspell?=		../../textproc/aspell

EVAL_PREFIX+=	BUILDLINK_PREFIX.aspell=aspell
BUILDLINK_PREFIX.aspell_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.aspell+=	include/aspell.h
BUILDLINK_FILES.aspell+=	include/pspell/pspell.h
BUILDLINK_FILES.aspell+=	lib/libaspell.*
BUILDLINK_FILES.aspell+=	lib/libpspell.*

BUILDLINK_TARGETS+=	aspell-buildlink

aspell-buildlink: _BUILDLINK_USE

.endif	# ASPELL_BUILDLINK2_MK
