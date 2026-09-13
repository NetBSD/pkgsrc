$NetBSD: patch-vault_quotas_quotas__rate__limit.go,v 1.1 2026/09/13 14:17:54 bsiegert Exp $

Adapt to new go-limiter API.
--- vault/quotas/quotas_rate_limit.go.orig	2021-08-24 20:52:56.000000000 +0000
+++ vault/quotas/quotas_rate_limit.go
@@ -1,6 +1,7 @@
 package quotas
 
 import (
+	"context"
 	"encoding/hex"
 	"fmt"
 	"math"
@@ -300,7 +301,10 @@ func (rlq *RateLimitQuota) allow(req *Re
 		}
 	}
 
-	limit, remaining, reset, allow := rlq.store.Take(req.ClientAddress)
+	limit, remaining, reset, allow, err := rlq.store.Take(context.TODO(), req.ClientAddress)
+	if err != nil {
+		return resp, err
+	}
 	resp.Allowed = allow
 	resp.Headers[httplimit.HeaderRateLimitLimit] = strconv.FormatUint(limit, 10)
 	resp.Headers[httplimit.HeaderRateLimitRemaining] = strconv.FormatUint(remaining, 10)
@@ -326,7 +330,7 @@ func (rlq *RateLimitQuota) close() error
 	}
 
 	if rlq.store != nil {
-		return rlq.store.Close()
+		return rlq.store.Close(context.TODO())
 	}
 
 	return nil
