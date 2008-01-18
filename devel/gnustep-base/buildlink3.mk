# $NetBSD: buildlink3.mk,v 1.13 2008/01/18 05:14:33 tnn Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNUSTEP_BASE_BUILDLINK3_MK:=	${GNUSTEP_BASE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnustep-base
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnustep-base}
BUILDLINK_PACKAGES+=	gnustep-base
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnustep-base

.if !empty(GNUSTEP_BASE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gnustep-base+=	gnustep-base>=1.9.1
BUILDLINK_ABI_DEPENDS.gnustep-base+=	gnustep-base>=1.14.1nb1
BUILDLINK_PKGSRCDIR.gnustep-base?=	../../devel/gnustep-base

PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Headers\/Foundation$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Headers\/GNUstepBase$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Headers\/GNUstepBase\/unicode$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Headers\/gnustep$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Headers\/gnustep\/base$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Headers\/gnustep\/unicode$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-base$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-base\/English.lproj$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-base\/French.lproj$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-base\/German.lproj$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-base\/Italian.lproj$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-base\/Languages$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-base\/NSCharacterSets$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-base\/NSTimeZones$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-base\/NSTimeZones\/zones$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/DTDs$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Documentation\/man\/man1$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Documentation\/man\/man8$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/DTDs$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Documentation\/man\/man1$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Documentation\/man\/man8$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Headers\/Foundation$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Headers\/GNUstepBase$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Headers\/GNUstepBase\/unicode$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Headers\/gnustep$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Headers\/gnustep\/base$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Headers\/gnustep\/unicode$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-base$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-base\/English.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-base\/French.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-base\/German.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-base\/Italian.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-base\/Languages$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-base\/NSCharacterSets$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-base\/NSTimeZones$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-base\/NSTimeZones\/zones$$/ { next; }

.endif	# GNUSTEP_BASE_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ffcall/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
