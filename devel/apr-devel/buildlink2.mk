# $NetBSD: buildlink2.mk,v 1.1 2002/11/09 15:17:17 wiz Exp $
#

.if !defined(APR_BUILDLINK2_MK)
APR_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		apr
BUILDLINK_DEPENDS.apr?=		apr>=0.20020725223645
BUILDLINK_PKGSRCDIR.apr?=	../../devel/apr-devel

EVAL_PREFIX+=	BUILDLINK_PREFIX.apr=apr
BUILDLINK_PREFIX.apr_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.apr+=	include/apr.h
BUILDLINK_FILES.apr+=	include/apr_allocator.h
BUILDLINK_FILES.apr+=	include/apr_anylock.h
BUILDLINK_FILES.apr+=	include/apr_atomic.h
BUILDLINK_FILES.apr+=	include/apr_base64.h
BUILDLINK_FILES.apr+=	include/apr_buckets.h
BUILDLINK_FILES.apr+=	include/apr_compat.h
BUILDLINK_FILES.apr+=	include/apr_date.h
BUILDLINK_FILES.apr+=	include/apr_dbm.h
BUILDLINK_FILES.apr+=	include/apr_dso.h
BUILDLINK_FILES.apr+=	include/apr_errno.h
BUILDLINK_FILES.apr+=	include/apr_file_info.h
BUILDLINK_FILES.apr+=	include/apr_file_io.h
BUILDLINK_FILES.apr+=	include/apr_fnmatch.h
BUILDLINK_FILES.apr+=	include/apr_general.h
BUILDLINK_FILES.apr+=	include/apr_getopt.h
BUILDLINK_FILES.apr+=	include/apr_global_mutex.h
BUILDLINK_FILES.apr+=	include/apr_hash.h
BUILDLINK_FILES.apr+=	include/apr_hooks.h
BUILDLINK_FILES.apr+=	include/apr_inherit.h
BUILDLINK_FILES.apr+=	include/apr_ldap.h
BUILDLINK_FILES.apr+=	include/apr_lib.h
BUILDLINK_FILES.apr+=	include/apr_md4.h
BUILDLINK_FILES.apr+=	include/apr_md5.h
BUILDLINK_FILES.apr+=	include/apr_mmap.h
BUILDLINK_FILES.apr+=	include/apr_network_io.h
BUILDLINK_FILES.apr+=	include/apr_optional.h
BUILDLINK_FILES.apr+=	include/apr_optional_hooks.h
BUILDLINK_FILES.apr+=	include/apr_poll.h
BUILDLINK_FILES.apr+=	include/apr_pools.h
BUILDLINK_FILES.apr+=	include/apr_portable.h
BUILDLINK_FILES.apr+=	include/apr_proc_mutex.h
BUILDLINK_FILES.apr+=	include/apr_ring.h
BUILDLINK_FILES.apr+=	include/apr_rmm.h
BUILDLINK_FILES.apr+=	include/apr_sdbm.h
BUILDLINK_FILES.apr+=	include/apr_sha1.h
BUILDLINK_FILES.apr+=	include/apr_shm.h
BUILDLINK_FILES.apr+=	include/apr_signal.h
BUILDLINK_FILES.apr+=	include/apr_strings.h
BUILDLINK_FILES.apr+=	include/apr_strmatch.h
BUILDLINK_FILES.apr+=	include/apr_support.h
BUILDLINK_FILES.apr+=	include/apr_tables.h
BUILDLINK_FILES.apr+=	include/apr_thread_cond.h
BUILDLINK_FILES.apr+=	include/apr_thread_mutex.h
BUILDLINK_FILES.apr+=	include/apr_thread_proc.h
BUILDLINK_FILES.apr+=	include/apr_thread_rwlock.h
BUILDLINK_FILES.apr+=	include/apr_time.h
BUILDLINK_FILES.apr+=	include/apr_uri.h
BUILDLINK_FILES.apr+=	include/apr_user.h
BUILDLINK_FILES.apr+=	include/apr_uuid.h
BUILDLINK_FILES.apr+=	include/apr_version.h
BUILDLINK_FILES.apr+=	include/apr_want.h
BUILDLINK_FILES.apr+=	include/apr_xlate.h
BUILDLINK_FILES.apr+=	include/apr_xml.h
BUILDLINK_FILES.apr+=	include/apu.h
BUILDLINK_FILES.apr+=	include/apu_compat.h
BUILDLINK_FILES.apr+=	lib/APRVARS
BUILDLINK_FILES.apr+=	lib/apr.exp
BUILDLINK_FILES.apr+=	lib/aprutil.exp
BUILDLINK_FILES.apr+=	lib/libapr.*
BUILDLINK_FILES.apr+=	lib/libaprutil.*

.include "../../textproc/expat/buildlink2.mk"

BUILDLINK_TARGETS+=	apr-buildlink

apr-buildlink: _BUILDLINK_USE

.endif	# APR_BUILDLINK2_MK
