# $NetBSD: buildlink3.mk,v 1.4 2004/09/20 14:50:28 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNUSTEP_MAKE_BUILDLINK3_MK:=	${GNUSTEP_MAKE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnustep-make
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnustep-make}
BUILDLINK_PACKAGES+=	gnustep-make

.if !empty(GNUSTEP_MAKE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnustep-make+=	gnustep-make>=1.9.1
BUILDLINK_PKGSRCDIR.gnustep-make?=	../../devel/gnustep-make

.include "../../devel/gnustep-make/gnustep.mk"

BUILDLINK_LIBDIRS.gnustep-make=	lib ${GNUSTEP_BLDIRS}
BUILDLINK_INCDIRS.gnustep-make=	include ${GNUSTEP_BIDIRS}

PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/Local\/Applications$$/ { print "@comment in gnustep-make: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/Local\/Headers$$/ { print "@comment in gnustep-make: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/Local\/Library$$/ { print "@comment in gnustep-make: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/Local\/Library\/Headers$$/ { print "@comment in gnustep-make: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/Local\/Library\/Libraries$$/ { print "@comment in gnustep-make: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library$$/ { print "@comment in gnustep-make: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Headers$$/ { print "@comment in gnustep-make: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Libraries$$/ { print "@comment in gnustep-make: " $$0; next; }

.endif	# GNUSTEP_MAKE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
