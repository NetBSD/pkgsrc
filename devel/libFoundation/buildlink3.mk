# $NetBSD: buildlink3.mk,v 1.10 2009/04/18 02:19:23 rh Exp $

BUILDLINK_TREE+=	libFoundation

.if !defined(LIBFOUNDATION_BUILDLINK3_MK)
LIBFOUNDATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libFoundation+=	libFoundation>=1.1.7.168
BUILDLINK_PKGSRCDIR.libFoundation?=	../../devel/libFoundation

PRINT_PLIST_AWK+=	/^@dirrm include\/libFoundation$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm include\/libFoundation\/${MACHINE_ARCH}$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm include\/libFoundation\/${MACHINE_ARCH}\/${LOWER_OPSYS}$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm include\/libFoundation\/${MACHINE_ARCH}\/${LOWER_OPSYS}\/GNU$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm include\/libFoundation\/Foundation$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm include\/libFoundation\/Foundation\/exceptions$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm include\/libFoundation\/extensions$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm include\/libFoundation\/extensions\/exceptions$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/${PKGNAME}$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources\/libFoundation$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources\/libFoundation\/CharacterSets$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources\/libFoundation\/Defaults$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources\/libFoundation\/TimeZoneInfo$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources\/libFoundation\/TimeZoneInfo\/Africa$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources\/libFoundation\/TimeZoneInfo\/Asia$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources\/libFoundation\/TimeZoneInfo\/Australia$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources\/libFoundation\/TimeZoneInfo\/Canada$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources\/libFoundation\/TimeZoneInfo\/Europe$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources\/libFoundation\/TimeZoneInfo\/SystemV$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources\/libFoundation\/TimeZoneInfo\/US$$/ { print "@comment in devel/libFoundation: " $$0; next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/include\/libFoundation$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/include\/libFoundation\/${MACHINE_ARCH}$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/include\/libFoundation\/${MACHINE_ARCH}\/${LOWER_OPSYS}$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/include\/libFoundation\/${MACHINE_ARCH}\/${LOWER_OPSYS}\/GNU$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/include\/libFoundation\/Foundation$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/include\/libFoundation\/Foundation\/exceptions$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/include\/libFoundation\/extensions$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/include\/libFoundation\/extensions\/exceptions$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/${PKGNAME}$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources\/libFoundation$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources\/libFoundation\/CharacterSets$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources\/libFoundation\/Defaults$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources\/libFoundation\/TimeZoneInfo$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources\/libFoundation\/TimeZoneInfo\/Africa$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources\/libFoundation\/TimeZoneInfo\/Asia$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources\/libFoundation\/TimeZoneInfo\/Australia$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources\/libFoundation\/TimeZoneInfo\/Canada$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources\/libFoundation\/TimeZoneInfo\/Europe$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources\/libFoundation\/TimeZoneInfo\/SystemV$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/${PKGNAME}\/Resources\/libFoundation\/TimeZoneInfo\/US$$/ { next; }

FOUNDATION_LIB?=	fd
ADDITIONAL_INCLUDE_DIRS+=-I${GNUSTEP_SYSTEM_ROOT}/Library/Headers/libFoundation/${GNUSTEP_HOST_CPU}/${LOWER_OPSYS}/GNU
.if !defined(NO_FOUNDATION_ENV)
CONFIGURE_ENV+=		FOUNDATION_LIB=${FOUNDATION_LIB:Q}
CONFIGURE_ENV+=		ADDITIONAL_INCLUDE_DIRS=${ADDITIONAL_INCLUDE_DIRS:Q}
MAKE_ENV+=		FOUNDATION_LIB=${FOUNDATION_LIB:Q}
MAKE_ENV+=		ADDITIONAL_INCLUDE_DIRS=${ADDITIONAL_INCLUDE_DIRS:Q}
.endif

.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../devel/gnustep-objc-lf2/buildlink3.mk"
.endif	# LIBFOUNDATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-libFoundation
