# $NetBSD: hacks.mk,v 1.1 2025/01/26 02:15:57 pho Exp $

.if !defined(FUSE_BINDFS_HACKS_MK)
FUSE_BINDFS_HACKS_MK=	defined

### [Sun Jan 16 10:03:54 JST 2025 : pho]
### Paper over a past issue in librefuse <fuse.h>. It failed to expose
### "struct fuse_operations" when the FUSE 3.4 API was requested. Any other
### API versions worked fine. This hack can be removed when NetBSD 10
### reaches EOL.
### https://mail-index.netbsd.org/source-changes/2025/01/26/msg155317.html
###
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 109911
PKG_HACKS+=	workaround-librefuse-bug
CPPFLAGS+=	-Dfuse_operations="_MK_FUSE_OPERATIONS_(_FUSE_OP_VERSION__)"
.endif

.endif  # FUSE_BINDFS_HACKS_MK
