# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:10:43 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBFOUNDATION_BUILDLINK3_MK:=	${LIBFOUNDATION_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libFoundation
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibFoundation}
BUILDLINK_PACKAGES+=	libFoundation
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libFoundation

.if !empty(LIBFOUNDATION_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libFoundation+=	libFoundation>=1.0.72.107nb1
BUILDLINK_ABI_DEPENDS.libFoundation?=	libFoundation>=1.0.72.107nb2
BUILDLINK_PKGSRCDIR.libFoundation?=	../../devel/libFoundation

PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Libraries$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Libraries\/Resources$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Libraries\/Resources\/libFoundation$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Libraries\/Resources\/libFoundation\/CharacterSets$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Libraries\/Resources\/libFoundation\/Defaults$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Libraries\/Resources\/libFoundation\/TimeZoneInfo$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Libraries\/Resources\/libFoundation\/TimeZoneInfo\/Africa$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Libraries\/Resources\/libFoundation\/TimeZoneInfo\/Asia$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Libraries\/Resources\/libFoundation\/TimeZoneInfo\/Australia$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Libraries\/Resources\/libFoundation\/TimeZoneInfo\/Canada$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Libraries\/Resources\/libFoundation\/TimeZoneInfo\/Europe$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Libraries\/Resources\/libFoundation\/TimeZoneInfo\/SystemV$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Libraries\/Resources\/libFoundation\/TimeZoneInfo\/US$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Headers\/libFoundation$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Headers\/libFoundation\/${GNUSTEP_HOST_CPU}$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Headers\/libFoundation\/${GNUSTEP_HOST_CPU}\/${LOWER_OPSYS}$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Headers\/libFoundation\/${GNUSTEP_HOST_CPU}\/${LOWER_OPSYS}\/GNU$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Headers\/libFoundation\/Foundation$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Headers\/libFoundation\/Foundation\/exceptions$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Headers\/libFoundation\/extensions$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Headers\/libFoundation\/extensions\/exceptions$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Libraries$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Libraries\/Resources$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Libraries\/Resources\/libFoundation$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Libraries\/Resources\/libFoundation\/CharacterSets$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Libraries\/Resources\/libFoundation\/Defaults$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Libraries\/Resources\/libFoundation\/TimeZoneInfo$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Libraries\/Resources\/libFoundation\/TimeZoneInfo\/Africa$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Libraries\/Resources\/libFoundation\/TimeZoneInfo\/Asia$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Libraries\/Resources\/libFoundation\/TimeZoneInfo\/Australia$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Libraries\/Resources\/libFoundation\/TimeZoneInfo\/Canada$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Libraries\/Resources\/libFoundation\/TimeZoneInfo\/Europe$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Libraries\/Resources\/libFoundation\/TimeZoneInfo\/SystemV$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Libraries\/Resources\/libFoundation\/TimeZoneInfo\/US$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Headers\/libFoundation$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Headers\/libFoundation\/${GNUSTEP_HOST_CPU}$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Headers\/libFoundation\/${GNUSTEP_HOST_CPU}\/${LOWER_OPSYS}$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Headers\/libFoundation\/${GNUSTEP_HOST_CPU}\/${LOWER_OPSYS}\/GNU$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Headers\/libFoundation\/Foundation$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Headers\/libFoundation\/Foundation\/exceptions$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Headers\/libFoundation\/extensions$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Headers\/libFoundation\/extensions\/exceptions$$/ { next; }

FOUNDATION_LIB?=	fd
ADDITIONAL_INCLUDE_DIRS+=-I${GNUSTEP_SYSTEM_ROOT}/Library/Headers/libFoundation/${GNUSTEP_HOST_CPU}/${LOWER_OPSYS}/GNU
.if !defined(NO_FOUNDATION_ENV)
CONFIGURE_ENV+=		FOUNDATION_LIB=${FOUNDATION_LIB:Q}
CONFIGURE_ENV+=		ADDITIONAL_INCLUDE_DIRS=${ADDITIONAL_INCLUDE_DIRS:Q}
MAKE_ENV+=		FOUNDATION_LIB=${FOUNDATION_LIB:Q}
MAKE_ENV+=		ADDITIONAL_INCLUDE_DIRS=${ADDITIONAL_INCLUDE_DIRS:Q}
.endif

.endif	# LIBFOUNDATION_BUILDLINK3_MK

.include "../../devel/gnustep-objc-lf2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
