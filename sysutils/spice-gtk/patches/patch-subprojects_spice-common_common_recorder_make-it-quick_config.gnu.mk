$NetBSD: patch-subprojects_spice-common_common_recorder_make-it-quick_config.gnu.mk,v 1.1 2022/07/11 07:52:57 wiz Exp $

Fix unportable test(1) operator.

--- subprojects/spice-common/common/recorder/make-it-quick/config.gnu.mk.orig	2020-12-01 16:32:04.099737200 +0000
+++ subprojects/spice-common/common/recorder/make-it-quick/config.gnu.mk
@@ -215,7 +215,7 @@ MIQ_CFGTEST=	"$<" -o "$<".exe > "$<".err
 		[ -x "$<".exe ] &&					\
 		"$<".exe > "$<".out					\
 		$(MIQ_CFGSET)
-MIQ_CFG_PRINT=	if [ $$MIQ_CFGRC == 1 ]; then				\
+MIQ_CFG_PRINT=	if [ $$MIQ_CFGRC = 1 ]; then				\
 		    echo "$(POS_COLOR)OK$(DEF_COLOR)";			\
 		else							\
 		    echo "$(ERR_COLOR)NO$(DEF_COLOR)";			\
