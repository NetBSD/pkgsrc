# $NetBSD: buildlink2.mk,v 1.8 2004/02/08 20:57:29 jmmv Exp $

.if !defined(INTLTOOL_BUILDLINK2_MK)
INTLTOOL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		intltool
BUILDLINK_DEPENDS.intltool?=	intltool>=0.30
BUILDLINK_PKGSRCDIR.intltool?=	../../textproc/intltool
BUILDLINK_DEPMETHOD.intltool?=	build

EVAL_PREFIX+=	BUILDLINK_PREFIX.intltool=intltool
BUILDLINK_PREFIX.intltool_DEFAULT=	${LOCALBASE}

USE_PERL5?=	build
.include "../../lang/perl5/buildlink2.mk"

CONFIGURE_ENV+=		INTLTOOL_PERL="${PERL5}"

INTLTOOLIZE=		${BUILDLINK_PREFIX.intltool}/bin/intltoolize

_CONFIGURE_PREREQ+=	intltoolize

intltoolize:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} "=> Overriding intltool."
	@cd ${WRKSRC} && ${INTLTOOLIZE} --force >/dev/null 2>&1

BUILDLINK_TARGETS+=	intltool-buildlink

intltool-buildlink: _BUILDLINK_USE

.endif	# INTLTOOL_BUILDLINK2_MK
