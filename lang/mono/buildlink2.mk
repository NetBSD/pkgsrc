# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/03/01 13:11:47 jmmv Exp $
#
# This Makefile fragment is included by packages that use mono.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(MONO_BUILDLINK2_MK)
MONO_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			mono
BUILDLINK_DEPENDS.mono?=		mono>=0.20
BUILDLINK_PKGSRCDIR.mono?=		../../lang/mono

EVAL_PREFIX+=	BUILDLINK_PREFIX.mono=mono
BUILDLINK_PREFIX.mono_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.mono+=	include/mono/cil/opcode.def
BUILDLINK_FILES.mono+=	include/mono/io-layer/access.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/atomic.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/context.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/critical-sections.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/error.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/events.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/handles.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/io-layer.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/io.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/macros.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/mono-mutex.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/mutexes.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/processes.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/semaphores.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/sockets.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/status.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/system.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/threads.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/timefuncs.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/types.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/uglify.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/versioninfo.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/wait.h
BUILDLINK_FILES.mono+=	include/mono/io-layer/wapi.h
BUILDLINK_FILES.mono+=	include/mono/jit/debug.h
BUILDLINK_FILES.mono+=	include/mono/jit/jit.h
BUILDLINK_FILES.mono+=	include/mono/jit/regset.h
BUILDLINK_FILES.mono+=	include/mono/metadata/appdomain.h
BUILDLINK_FILES.mono+=	include/mono/metadata/assembly.h
BUILDLINK_FILES.mono+=	include/mono/metadata/blob.h
BUILDLINK_FILES.mono+=	include/mono/metadata/cil-coff.h
BUILDLINK_FILES.mono+=	include/mono/metadata/class.h
BUILDLINK_FILES.mono+=	include/mono/metadata/debug-helpers.h
BUILDLINK_FILES.mono+=	include/mono/metadata/debug-mono-symfile.h
BUILDLINK_FILES.mono+=	include/mono/metadata/environment.h
BUILDLINK_FILES.mono+=	include/mono/metadata/exception.h
BUILDLINK_FILES.mono+=	include/mono/metadata/image.h
BUILDLINK_FILES.mono+=	include/mono/metadata/loader.h
BUILDLINK_FILES.mono+=	include/mono/metadata/mempool.h
BUILDLINK_FILES.mono+=	include/mono/metadata/metadata.h
BUILDLINK_FILES.mono+=	include/mono/metadata/monitor.h
BUILDLINK_FILES.mono+=	include/mono/metadata/mono-endian.h
BUILDLINK_FILES.mono+=	include/mono/metadata/object.h
BUILDLINK_FILES.mono+=	include/mono/metadata/opcodes.h
BUILDLINK_FILES.mono+=	include/mono/metadata/profiler.h
BUILDLINK_FILES.mono+=	include/mono/metadata/rand.h
BUILDLINK_FILES.mono+=	include/mono/metadata/rawbuffer.h
BUILDLINK_FILES.mono+=	include/mono/metadata/reflection.h
BUILDLINK_FILES.mono+=	include/mono/metadata/row-indexes.h
BUILDLINK_FILES.mono+=	include/mono/metadata/tabledefs.h
BUILDLINK_FILES.mono+=	include/mono/metadata/threadpool.h
BUILDLINK_FILES.mono+=	include/mono/metadata/threads-types.h
BUILDLINK_FILES.mono+=	include/mono/metadata/threads.h
BUILDLINK_FILES.mono+=	include/mono/metadata/tokentype.h
BUILDLINK_FILES.mono+=	include/mono/metadata/verify.h
BUILDLINK_FILES.mono+=	include/mono/utils/mono-digest.h
BUILDLINK_FILES.mono+=	include/mono/utils/mono-hash.h
BUILDLINK_FILES.mono+=	include/mono/utils/monobitset.h
BUILDLINK_FILES.mono+=	lib/Accessibility.dll
BUILDLINK_FILES.mono+=	lib/Cscompmgd.dll
BUILDLINK_FILES.mono+=	lib/I18N.CJK.dll
BUILDLINK_FILES.mono+=	lib/I18N.MidEast.dll
BUILDLINK_FILES.mono+=	lib/I18N.Other.dll
BUILDLINK_FILES.mono+=	lib/I18N.Rare.dll
BUILDLINK_FILES.mono+=	lib/I18N.West.dll
BUILDLINK_FILES.mono+=	lib/I18N.dll
BUILDLINK_FILES.mono+=	lib/Microsoft.VisualBasic.dll
BUILDLINK_FILES.mono+=	lib/Microsoft.VisualC.dll
BUILDLINK_FILES.mono+=	lib/Mono.CSharp.Debugger.dll
BUILDLINK_FILES.mono+=	lib/Mono.Data.DB2Client.dll
BUILDLINK_FILES.mono+=	lib/Mono.Data.MySql.dll
BUILDLINK_FILES.mono+=	lib/Mono.Data.PostgreSqlClient.dll
BUILDLINK_FILES.mono+=	lib/Mono.Data.SqliteClient.dll
BUILDLINK_FILES.mono+=	lib/Mono.Data.SybaseClient.dll
BUILDLINK_FILES.mono+=	lib/Mono.Data.Tds.dll
BUILDLINK_FILES.mono+=	lib/Mono.Data.TdsClient.dll
BUILDLINK_FILES.mono+=	lib/Mono.GetOptions.dll
BUILDLINK_FILES.mono+=	lib/Mono.PEToolkit.dll
BUILDLINK_FILES.mono+=	lib/NUnitCore_mono.dll
BUILDLINK_FILES.mono+=	lib/System.Configuration.Install.dll
BUILDLINK_FILES.mono+=	lib/System.Data.OracleClient.dll
BUILDLINK_FILES.mono+=	lib/System.Data.dll
BUILDLINK_FILES.mono+=	lib/System.Drawing.dll
BUILDLINK_FILES.mono+=	lib/System.EnterpriseServices.dll
BUILDLINK_FILES.mono+=	lib/System.Runtime.Remoting.dll
BUILDLINK_FILES.mono+=	lib/System.Runtime.Serialization.Formatters.Soap.dll
BUILDLINK_FILES.mono+=	lib/System.Security.dll
BUILDLINK_FILES.mono+=	lib/System.Web.Services.dll
BUILDLINK_FILES.mono+=	lib/System.Web.dll
BUILDLINK_FILES.mono+=	lib/System.Windows.Forms.dll
BUILDLINK_FILES.mono+=	lib/System.Xml.dll
BUILDLINK_FILES.mono+=	lib/System.dll
BUILDLINK_FILES.mono+=	lib/corlib.dll
BUILDLINK_FILES.mono+=	lib/libmono.*
BUILDLINK_FILES.mono+=	lib/pkgconfig/mono.pc

.include "../../devel/boehm-gc/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"

BUILDLINK_TARGETS+=	mono-buildlink

mono-buildlink: _BUILDLINK_USE

.endif	# MONO_BUILDLINK2_MK
