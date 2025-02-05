$NetBSD: patch-gcc_target.h,v 1.1 2025/02/05 16:30:36 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/target.h
+++ gcc/target.h
@@ -51,22 +51,8 @@
 #include "insn-codes.h"
 #include "tm.h"
 #include "hard-reg-set.h"
-
-#if CHECKING_P
-
-struct cumulative_args_t { void *magic; void *p; };
-
-#else /* !CHECKING_P */
-
-/* When using a GCC build compiler, we could use
-   __attribute__((transparent_union)) to get cumulative_args_t function
-   arguments passed like scalars where the ABI would mandate a less
-   efficient way of argument passing otherwise.  However, that would come
-   at the cost of less type-safe !CHECKING_P compilation.  */
-
-union cumulative_args_t { void *p; };
-
-#endif /* !CHECKING_P */
+#include "tree-core.h"
+#include "cumulative-args.h"

 /* Target properties of _BitInt(N) type.  _BitInt(N) is to be represented
    as series of abi_limb_mode CEIL (N, GET_MODE_PRECISION (abi_limb_mode))
