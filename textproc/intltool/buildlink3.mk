# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 00:48:58 xtraeme Exp $
#
# This Makefile fragment is included by packages that use intltool.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
INTLTOOL_BUILDLINK3_MK:=	${INTLTOOL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	intltool
.endif

.if !empty(INTLTOOL_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			intltool
BUILDLINK_DEPENDS.intltool+=		intltool>=0.30
BUILDLINK_PKGSRCDIR.intltool?=		../../textproc/intltool
BUILDLINK_DEPMETHOD.intltool?=		build

USE_PERL5?=	build

.include "../../lang/perl5/buildlink3.mk"

CONFIGURE_ENV+=		INTLTOOL_PERL="${PERL5}"
INTLTOOLIZE=		${BUILDLINK_PREFIX.intltool}/bin/intltoolize

_CONFIGURE_PREREQ+=	intltoolize

intltoolize:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} "=> Overriding intltool."
	@cd ${WRKSRC} && ${INTLTOOLIZE} --force >/dev/null 2>&1

.endif # INTLTOOL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
