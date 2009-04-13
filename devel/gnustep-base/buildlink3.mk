# $NetBSD: buildlink3.mk,v 1.15 2009/04/13 12:16:24 rh Exp $

BUILDLINK_TREE+=	gnustep-base

.if !defined(GNUSTEP_BASE_BUILDLINK3_MK)
GNUSTEP_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnustep-base+=	gnustep-base>=1.18.0
BUILDLINK_ABI_DEPENDS.gnustep-base+=	gnustep-base>=1.18.0
BUILDLINK_PKGSRCDIR.gnustep-base?=	../../devel/gnustep-base

PRINT_PLIST_AWK+=	/^@dirrm include\/Foundation$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm include\/GNUstepBase$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm include\/GNUstepBase\/unicode$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm include\/gnustep$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm include\/gnustep\/base$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm include\/gnustep\/unicode$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Bundles$$/ { print "@comment in x11/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/DTDs$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Frameworks$$/ { print "@comment in x11/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/English.lproj$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/Esperanto.lproj$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/French.lproj$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/German.lproj$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/Italian.lproj$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/Korean.lproj$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/Languages$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Africa$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/America$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/America\/Argentina$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/America\/Indiana$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/America\/Kentucky$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/America\/North_Dakota$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Antarctica$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Arctic$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Asia$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Atlantic$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Australia$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Brazil$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Canada$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Chile$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Etc$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Europe$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Indian$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Mexico$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Mideast$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Pacific$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/US$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/SSL.bundle$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/SSL.bundle\/Resources$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/Spanish.lproj$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/TraditionalChinese.lproj$$/ { print "@comment in devel/gnustep-base: " $$0; next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/include\/Foundation$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/include\/GNUstepBase$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/include\/GNUstepBase\/unicode$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/include\/gnustep$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/include\/gnustep\/base$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/include\/gnustep\/unicode$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Bundles$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/DTDs$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Frameworks$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/English.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/Esperanto.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/French.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/German.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/Italian.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/Korean.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/Languages$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Africa$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/America$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/America\/Argentina$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/America\/Indiana$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/America\/Kentucky$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/America\/North_Dakota$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Antarctica$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Arctic$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Asia$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Atlantic$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Australia$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Brazil$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Canada$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Chile$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Etc$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Europe$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Indian$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Mexico$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Mideast$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/Pacific$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/NSTimeZones\/zones\/US$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/SSL.bundle$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/SSL.bundle\/Resources$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/Spanish.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Libraries\/gnustep-base\/Versions\/1.18\/Resources\/TraditionalChinese.lproj$$/ { next; }

.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../devel/gnustep-objc/buildlink3.mk"
.endif # GNUSTEP_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnustep-base
