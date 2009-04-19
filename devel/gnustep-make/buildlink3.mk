# $NetBSD: buildlink3.mk,v 1.16 2009/04/19 00:50:11 rh Exp $

BUILDLINK_TREE+=	gnustep-make

.if !defined(GNUSTEP_MAKE_BUILDLINK3_MK)
GNUSTEP_MAKE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnustep-make+=	gnustep-make>=2.0.8nb2
BUILDLINK_ABI_DEPENDS.gnustep-make?=	gnustep-make>=2.0.8nb2
BUILDLINK_PKGSRCDIR.gnustep-make?=	../../devel/gnustep-make

.include "../../devel/gnustep-make/gnustep.mk"

BUILDLINK_LIBDIRS.gnustep-make=	lib ${GNUSTEP_BLDIRS}
BUILDLINK_INCDIRS.gnustep-make=	include ${GNUSTEP_BIDIRS}

PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep$$/ { print "@comment in devel/gnustep-make: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/Library$$/ { print "@comment in devel/gnustep-make: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/Makefiles$$/ { print "@comment in devel/gnustep-make: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/Makefiles\/${GNUSTEP_ARCH}$$/ { print "@comment in devel/gnustep-make: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/Makefiles\/Additional$$/ { print "@comment in devel/gnustep-make: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/Makefiles\/Auxiliary$$/ { print "@comment in devel/gnustep-make: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/Makefiles\/Instance$$/ { print "@comment in devel/gnustep-make: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/Makefiles\/Instance\/Documentation$$/ { print "@comment in devel/gnustep-make: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/Makefiles\/Instance\/Shared$$/ { print "@comment in devel/gnustep-make: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/Makefiles\/Master$$/ { print "@comment in devel/gnustep-make: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/examples\/GNUstep$$/ { print "@comment in devel/gnustep-make: " $$0; next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/Library$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/Makefiles$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/Makefiles\/${GNUSTEP_ARCH}$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/Makefiles\/Additional$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/Makefiles\/Auxiliary$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/Makefiles\/Instance$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/Makefiles\/Instance\/Documentation$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/Makefiles\/Instance\/Shared$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/Makefiles\/Master$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/examples\/GNUstep$$/ { next; }

.endif # GNUSTEP_MAKE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnustep-make
