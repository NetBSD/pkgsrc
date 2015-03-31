$NetBSD: patch-drz80_drz80.s,v 1.1 2015/03/31 15:20:53 joerg Exp $

--- drz80/drz80.s.orig	2013-02-09 20:26:18.000000000 +0000
+++ drz80/drz80.s
@@ -252,7 +252,7 @@ pico_z80_write16: @ data, addr
 	sub r2,z80pc,r1
 	str r2,[cpucontext,#previouspc]
 .endif
-	ldrplb r0,[z80pc],#1
+	ldrbpl r0,[z80pc],#1
 	ldrpl pc,[opcodes,r0, lsl #2]
 	bmi z80_execute_end
 .endm
@@ -1385,7 +1385,7 @@ DrZ80Run:
 .if INTERRUPT_MODE == 0
 	;@ check ints
 	tst r0,#1
-	movnes r0,r0,lsr #8
+	movsne r0,r0,lsr #8
     blne DoInterrupt
 .endif
 
@@ -1529,7 +1529,7 @@ DoInterrupt_end:
 	;@ interupt accepted so callback irq interface
 	ldr r0,[cpucontext, #z80irqcallback]
 	tst r0,r0
-	ldmeqfd sp!,{pc}
+	ldmfdeq sp!,{pc}
 	stmfd sp!,{r3,r12}
 	mov lr,pc
 	mov pc,r0    ;@ call callback function
@@ -5636,7 +5636,7 @@ ei_return:
 	ldr opcodes,MAIN_opcodes_POINTER
 	;@ check ints
 	tst r0,#1
-	movnes r0,r0,lsr #8
+	movsne r0,r0,lsr #8
     blne DoInterrupt
 	;@ continue
 ei_return_exit:
