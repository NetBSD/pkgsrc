$NetBSD: patch-src_emu_hiscore.c,v 1.1 2020/05/14 19:35:59 joerg Exp $

--- src/emu/hiscore.c.orig	2020-05-13 15:19:06.758626807 +0000
+++ src/emu/hiscore.c
@@ -48,7 +48,7 @@ static void copy_to_memory (running_mach
 {
 	int i;
 	const address_space *targetspace;
-	if (strstr(machine->gamedrv->source_file,"cinemat.c") > 0)
+	if (strstr(machine->gamedrv->source_file,"cinemat.c"))
 	{
 		 targetspace = cpu_get_address_space(machine->cpu[cpu], ADDRESS_SPACE_DATA);
 	}
@@ -67,7 +67,7 @@ static void copy_from_memory (running_ma
 {
 	int i;
 	const address_space *targetspace;
-	if (strstr(machine->gamedrv->source_file,"cinemat.c") > 0)
+	if (strstr(machine->gamedrv->source_file,"cinemat.c"))
 	{
 		 targetspace = cpu_get_address_space(machine->cpu[cpu], ADDRESS_SPACE_DATA);
 	}
@@ -166,7 +166,7 @@ static int safe_to_load (running_machine
 {
 	memory_range *mem_range = state.mem_range;
 	const address_space *srcspace;
-	if (strstr(machine->gamedrv->source_file,"cinemat.c") > 0)
+	if (strstr(machine->gamedrv->source_file,"cinemat.c"))
 	{
 		srcspace = cpu_get_address_space(machine->cpu[mem_range->cpu], ADDRESS_SPACE_DATA);
 	}
@@ -316,7 +316,7 @@ void hiscore_init (running_machine *mach
 	while (mem_range)
 	{
 
-		if (strstr(machine->gamedrv->source_file,"cinemat.c") > 0)
+		if (strstr(machine->gamedrv->source_file,"cinemat.c"))
 		{
 			memory_write_byte(
 				cpu_get_address_space(machine->cpu[mem_range->cpu], ADDRESS_SPACE_DATA),
