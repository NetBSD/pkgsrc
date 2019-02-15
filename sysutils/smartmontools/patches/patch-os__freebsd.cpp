$NetBSD: patch-os__freebsd.cpp,v 1.1 2019/02/15 20:38:29 triaxx Exp $

* Big-endian support has been added to NVMe in FreeBSD 1200059: status field of
  struct nvme_completion changed from struct nvme_status to uint16_t.
  https://svnweb.freebsd.org/base/stable/12/sys/dev/nvme/nvme.h?revision=329824

--- os_freebsd.cpp.orig	2018-12-05 18:30:46.000000000 +0000
+++ os_freebsd.cpp
@@ -542,7 +542,12 @@ bool freebsd_nvme_device::nvme_pass_through(const nvme
   out.result=cp_p->cdw0; // Command specific result (DW0)
 
   if (nvme_completion_is_error(cp_p)) {  /* ignore DNR and More bits */
+#if __FreeBSD_version < 1200059
     uint16_t nvme_status = ((cp_p->status.sct << 8) | cp_p->status.sc) & 0x3ff;
+#else
+    uint16_t nvme_status = NVME_STATUS_GET_SCT(cp_p->status) |
+                           NVME_STATUS_GET_SC(cp_p->status);
+#endif
 
     return set_nvme_err(out, nvme_status);
   }
