# $NetBSD: buildlink2.mk,v 1.6 2004/03/26 02:27:37 wiz Exp $

.if !defined(TCL_POSTGRESQL_BUILDLINK2_MK)
TCL_POSTGRESQL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			tcl-postgresql
BUILDLINK_DEPENDS.tcl-postgresql?=	tcl-postgresql>=7.3.1
BUILDLINK_RECOMMENDED.tcl-postgresql?=	tcl-postgresql>=7.3.4nb3
BUILDLINK_PKGSRCDIR.tcl-postgresql?=	../../databases/tcl-postgresql

EVAL_PREFIX+=	BUILDLINK_PREFIX.tcl-postgresql=tcl-postgresql
BUILDLINK_PREFIX.tcl-postgresql_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.tcl-postgresql=		include/pgsql/libpgtcl.h
BUILDLINK_FILES.tcl-postgresql+=	lib/libpgtcl.*

.include "../../lang/tcl/buildlink2.mk"

BUILDLINK_TARGETS+=	tcl-postgresql-buildlink

tcl-postgresql-buildlink: _BUILDLINK_USE

.endif	# TCL_POSTGRESQL_BUILDLINK2_MK
