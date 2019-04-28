$NetBSD: patch-src_osip2_port__sema.c,v 1.1.2.2 2019/04/28 16:14:29 bsiegert Exp $

Fix the calls to semctl to make this package build on NetBSD 1.6

--- src/osip2/port_sema.c.orig	2013-12-18 18:36:46.000000000 +0000
+++ src/osip2/port_sema.c
@@ -305,7 +305,6 @@ osip_sem_trywait (struct osip_sem *_sem)
 struct osip_sem *
 osip_sem_init (unsigned int value)
 {
-  union semun val;
   int i;
   osip_sem_t *sem = (osip_sem_t *) osip_malloc (sizeof (osip_sem_t));
 
@@ -318,8 +317,7 @@ osip_sem_init (unsigned int value)
     osip_free (sem);
     return NULL;
   }
-  val.val = (int) value;
-  i = semctl (sem->semid, 0, SETVAL, val);
+  i = semctl(sem->semid, 0, SETVAL, value);
   if (i != 0) {
     perror ("semctl error");
     osip_free (sem);
@@ -331,13 +329,11 @@ osip_sem_init (unsigned int value)
 int
 osip_sem_destroy (struct osip_sem *_sem)
 {
-  union semun val;
   osip_sem_t *sem = (osip_sem_t *) _sem;
 
   if (sem == NULL)
     return OSIP_SUCCESS;
-  val.val = 0;
-  semctl (sem->semid, 0, IPC_RMID, val);
+  semctl(sem->semid, 0, IPC_RMID, 0);
   osip_free (sem);
   return OSIP_SUCCESS;
 }
