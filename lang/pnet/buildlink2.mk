# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/01/12 17:13:32 xtraeme Exp $
#
# This Makefile fragment is included by packages that use pnet.
#
# This file was created automatically using createbuildlink 2.9.
#

.if !defined(PNET_BUILDLINK2_MK)
PNET_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			pnet
BUILDLINK_DEPENDS.pnet?=		pnet>=0.6.2
BUILDLINK_PKGSRCDIR.pnet?=		../../lang/pnet

EVAL_PREFIX+=	BUILDLINK_PREFIX.pnet=pnet
BUILDLINK_PREFIX.pnet_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pnet+=	include/pnet/ffi.h
BUILDLINK_FILES.pnet+=	include/pnet/ffi_mips.h
BUILDLINK_FILES.pnet+=	include/pnet/fficonfig.h
BUILDLINK_FILES.pnet+=	include/pnet/gc.h
BUILDLINK_FILES.pnet+=	include/pnet/gc_local_alloc.h
BUILDLINK_FILES.pnet+=	include/pnet/gc_typed.h
BUILDLINK_FILES.pnet+=	include/pnet/il_align.h
BUILDLINK_FILES.pnet+=	include/pnet/il_bignum.h
BUILDLINK_FILES.pnet+=	include/pnet/il_coder.h
BUILDLINK_FILES.pnet+=	include/pnet/il_config.h
BUILDLINK_FILES.pnet+=	include/pnet/il_console.h
BUILDLINK_FILES.pnet+=	include/pnet/il_crypt.h
BUILDLINK_FILES.pnet+=	include/pnet/il_debug.h
BUILDLINK_FILES.pnet+=	include/pnet/il_decimal.h
BUILDLINK_FILES.pnet+=	include/pnet/il_dumpasm.h
BUILDLINK_FILES.pnet+=	include/pnet/il_engine.h
BUILDLINK_FILES.pnet+=	include/pnet/il_errno.h
BUILDLINK_FILES.pnet+=	include/pnet/il_gc.h
BUILDLINK_FILES.pnet+=	include/pnet/il_image.h
BUILDLINK_FILES.pnet+=	include/pnet/il_jopcodes.h
BUILDLINK_FILES.pnet+=	include/pnet/il_linker.h
BUILDLINK_FILES.pnet+=	include/pnet/il_meta.h
BUILDLINK_FILES.pnet+=	include/pnet/il_opcodes.h
BUILDLINK_FILES.pnet+=	include/pnet/il_profile.h
BUILDLINK_FILES.pnet+=	include/pnet/il_program.h
BUILDLINK_FILES.pnet+=	include/pnet/il_regex.h
BUILDLINK_FILES.pnet+=	include/pnet/il_serial.h
BUILDLINK_FILES.pnet+=	include/pnet/il_serialize.h
BUILDLINK_FILES.pnet+=	include/pnet/il_sysio.h
BUILDLINK_FILES.pnet+=	include/pnet/il_system.h
BUILDLINK_FILES.pnet+=	include/pnet/il_thread.h
BUILDLINK_FILES.pnet+=	include/pnet/il_types.h
BUILDLINK_FILES.pnet+=	include/pnet/il_utils.h
BUILDLINK_FILES.pnet+=	include/pnet/il_values.h
BUILDLINK_FILES.pnet+=	include/pnet/il_writer.h
BUILDLINK_FILES.pnet+=	include/pnet/il_xml.h
BUILDLINK_FILES.pnet+=	include/pnet/leak_detector.h
BUILDLINK_FILES.pnet+=	lib/cscc/plugins/cscc-b
BUILDLINK_FILES.pnet+=	lib/cscc/plugins/cscc-bf
BUILDLINK_FILES.pnet+=	lib/cscc/plugins/cscc-c-s
BUILDLINK_FILES.pnet+=	lib/cscc/plugins/cscc-cs
BUILDLINK_FILES.pnet+=	lib/cscc/plugins/cscc-csharp
BUILDLINK_FILES.pnet+=	lib/cscc/plugins/cscc-java
BUILDLINK_FILES.pnet+=	lib/cscc/plugins/cscc-vb
BUILDLINK_FILES.pnet+=	lib/libILAsm.*
BUILDLINK_FILES.pnet+=	lib/libILCodeGen.*
BUILDLINK_FILES.pnet+=	lib/libILDumpAsm.*
BUILDLINK_FILES.pnet+=	lib/libILEngine.*
BUILDLINK_FILES.pnet+=	lib/libILImage.*
BUILDLINK_FILES.pnet+=	lib/libILLink.*
BUILDLINK_FILES.pnet+=	lib/libILSupport.*
BUILDLINK_FILES.pnet+=	lib/pnet/libffi.*
BUILDLINK_FILES.pnet+=	lib/pnet/libgc.*

BUILDLINK_TARGETS+=	pnet-buildlink

pnet-buildlink: _BUILDLINK_USE

.endif	# PNET_BUILDLINK2_MK
