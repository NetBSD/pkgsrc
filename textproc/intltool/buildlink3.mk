# $NetBSD: buildlink3.mk,v 1.4 2004/06/27 17:27:12 jmmv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
INTLTOOL_BUILDLINK3_MK:=	${INTLTOOL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	intltool
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nintltool}
BUILDLINK_PACKAGES+=	intltool

.if !empty(INTLTOOL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.intltool+=	intltool>=0.31
BUILDLINK_PKGSRCDIR.intltool?=	../../textproc/intltool
BUILDLINK_DEPMETHOD.intltool?=	build
.endif	# INTLTOOL_BUILDLINK3_MK

USE_PERL5?=	build

.include "../../lang/perl5/buildlink3.mk"

.if !empty(INTLTOOL_BUILDLINK3_MK:M+)
CONFIGURE_ENV+=		INTLTOOL_PERL="${PERL5}"
INTLTOOLIZE=		${BUILDLINK_PREFIX.intltool}/bin/intltoolize

_CONFIGURE_PREREQ+=	intltoolize

.PHONY: intltoolize
intltoolize:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} "=> Overriding intltool."
	@cd ${WRKSRC} && ${INTLTOOLIZE} --force >/dev/null 2>&1
.endif	# INTLTOOL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
