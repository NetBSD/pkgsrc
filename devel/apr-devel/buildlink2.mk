# $NetBSD: buildlink2.mk,v 1.2 2002/11/25 19:52:44 wiz Exp $
#

.if !defined(APR_BUILDLINK2_MK)
APR_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		apr
BUILDLINK_DEPENDS.apr?=		apr>=0.20021123173453
BUILDLINK_PKGSRCDIR.apr?=	../../devel/apr-devel

EVAL_PREFIX+=	BUILDLINK_PREFIX.apr=apr
BUILDLINK_PREFIX.apr_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.apr+=	include/apr-0/apr.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_version.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_user.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_time.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_thread_rwlock.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_thread_proc.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_thread_mutex.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_thread_cond.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_tables.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_support.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_strings.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_signal.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_shm.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_ring.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_proc_mutex.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_portable.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_pools.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_poll.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_network_io.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_mmap.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_lib.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_inherit.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_hash.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_global_mutex.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_getopt.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_general.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_fnmatch.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_file_io.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_file_info.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_errno.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_dso.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_compat.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_atomic.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_allocator.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_want.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_anylock.h
BUILDLINK_FILES.apr+=	include/apr-0/apu_compat.h
BUILDLINK_FILES.apr+=	include/apr-0/apu.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_xml.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_xlate.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_uuid.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_uri.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_strmatch.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_sha1.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_sdbm.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_rmm.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_reslist.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_queue.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_optional_hooks.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_optional.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_md5.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_md4.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_ldap.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_hooks.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_dbm.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_date.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_buckets.h
BUILDLINK_FILES.apr+=	include/apr-0/apr_base64.h
BUILDLINK_FILES.apr+=	include/apr-0/apu_version.h
BUILDLINK_FILES.apr+=	lib/apr.exp
BUILDLINK_FILES.apr+=	lib/aprutil.exp
BUILDLINK_FILES.apr+=	lib/libapr-0.*
BUILDLINK_FILES.apr+=	lib/libaprutil-0.*

.include "../../textproc/expat/buildlink2.mk"

BUILDLINK_TARGETS+=	apr-buildlink

apr-buildlink: _BUILDLINK_USE

.endif	# APR_BUILDLINK2_MK
