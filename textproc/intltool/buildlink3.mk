# $NetBSD: buildlink3.mk,v 1.5 2004/10/02 13:58:58 jmmv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
INTLTOOL_BUILDLINK3_MK:=	${INTLTOOL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	intltool
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nintltool}
BUILDLINK_PACKAGES+=	intltool

.if !empty(INTLTOOL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.intltool+=	intltool>=0.31.3
BUILDLINK_PKGSRCDIR.intltool?=	../../textproc/intltool
BUILDLINK_DEPMETHOD.intltool?=	build
.endif	# INTLTOOL_BUILDLINK3_MK

USE_PERL5?=	build

.include "../../lang/perl5/buildlink3.mk"

.if !empty(INTLTOOL_BUILDLINK3_MK:M+)
CONFIGURE_ENV+=		INTLTOOL_PERL="${PERL5}"
INTLTOOLIZE=		${BUILDLINK_PREFIX.intltool}/bin/intltoolize
INTLTOOL_OVERRIDE?=	intltool-* */intltool-*

_CONFIGURE_POSTREQ+=	override-intltool

.PHONY: override-intltool
override-intltool:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} "=> Overriding intltool."
	@cd ${WRKSRC} && for f in ${INTLTOOL_OVERRIDE}; do		\
	    if ${TEST} -f ${BUILDLINK_PREFIX.intltool}/bin/${f}; then	\
	        ${CP} ${BUILDLINK_PREFIX.intltool}/bin/${f} ${f};	\
	    fi;								\
	done
.endif	# INTLTOOL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
