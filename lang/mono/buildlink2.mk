# $NetBSD: buildlink2.mk,v 1.7 2003/09/25 16:05:21 recht Exp $

.if !defined(MONO_BUILDLINK2_MK)
MONO_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			mono
BUILDLINK_DEPENDS.mono?=		mono>=0.26
BUILDLINK_PKGSRCDIR.mono?=		../../lang/mono

EVAL_PREFIX+=	BUILDLINK_PREFIX.mono=mono
BUILDLINK_PREFIX.mono_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.mono+=	include/mono/cil/opcode.def
BUILDLINK_FILES.mono+=	include/mono/io-layer/*.h
BUILDLINK_FILES.mono+=	include/mono/jit/*.h
BUILDLINK_FILES.mono+=	include/mono/metadata/*.h
BUILDLINK_FILES.mono+=	include/mono/private/*.h
BUILDLINK_FILES.mono+=	include/mono/utils/*.h
BUILDLINK_FILES.mono+=	lib/Accessibility.dll
BUILDLINK_FILES.mono+=	lib/ByteFX.Data.dll
BUILDLINK_FILES.mono+=	lib/Commons.Xml.Relaxng.dll
BUILDLINK_FILES.mono+=	lib/Cscompmgd.dll
BUILDLINK_FILES.mono+=	lib/I18N.CJK.dll
BUILDLINK_FILES.mono+=	lib/I18N.MidEast.dll
BUILDLINK_FILES.mono+=	lib/I18N.Other.dll
BUILDLINK_FILES.mono+=	lib/I18N.Rare.dll
BUILDLINK_FILES.mono+=	lib/I18N.West.dll
BUILDLINK_FILES.mono+=	lib/I18N.dll
BUILDLINK_FILES.mono+=	lib/ICSharpCode.SharpZipLib.dll
BUILDLINK_FILES.mono+=	lib/Microsoft.VisualBasic.dll
BUILDLINK_FILES.mono+=	lib/Microsoft.VisualC.dll
BUILDLINK_FILES.mono+=	lib/Microsoft.Vsa.dll
BUILDLINK_FILES.mono+=	lib/Mono.CSharp.Debugger.dll
BUILDLINK_FILES.mono+=	lib/Mono.Cairo.dll
BUILDLINK_FILES.mono+=	lib/Mono.Data.DB2Client.dll
BUILDLINK_FILES.mono+=	lib/Mono.Data.MySql.dll
BUILDLINK_FILES.mono+=	lib/Mono.Data.PostgreSqlClient.dll
BUILDLINK_FILES.mono+=	lib/Mono.Data.SqliteClient.dll
BUILDLINK_FILES.mono+=	lib/Mono.Data.SybaseClient.dll
BUILDLINK_FILES.mono+=	lib/Mono.Data.Tds.dll
BUILDLINK_FILES.mono+=	lib/Mono.Data.TdsClient.dll
BUILDLINK_FILES.mono+=	lib/Mono.Directory.LDAP.dll
BUILDLINK_FILES.mono+=	lib/Mono.GetOptions.dll
BUILDLINK_FILES.mono+=	lib/Mono.Http.dll
BUILDLINK_FILES.mono+=	lib/Mono.PEToolkit.dll
BUILDLINK_FILES.mono+=	lib/Mono.Posix.dll
BUILDLINK_FILES.mono+=	lib/Mono.Security.Win32.dll
BUILDLINK_FILES.mono+=	lib/Mono.Security.dll
BUILDLINK_FILES.mono+=	lib/NUnit.Framework.dll
BUILDLINK_FILES.mono+=	lib/NUnit.Util.dll
BUILDLINK_FILES.mono+=	lib/Npgsql.dll
BUILDLINK_FILES.mono+=	lib/PEAPI.dll
BUILDLINK_FILES.mono+=	lib/System.Configuration.Install.dll
BUILDLINK_FILES.mono+=	lib/System.Data.OracleClient.dll
BUILDLINK_FILES.mono+=	lib/System.Data.dll
BUILDLINK_FILES.mono+=	lib/System.Design.dll
BUILDLINK_FILES.mono+=	lib/System.DirectoryServices.dll
BUILDLINK_FILES.mono+=	lib/System.Drawing.Design.dll
BUILDLINK_FILES.mono+=	lib/System.Drawing.dll
BUILDLINK_FILES.mono+=	lib/System.EnterpriseServices.dll
BUILDLINK_FILES.mono+=	lib/System.Management.dll
BUILDLINK_FILES.mono+=	lib/System.Messaging.dll
BUILDLINK_FILES.mono+=	lib/System.Runtime.Remoting.dll
BUILDLINK_FILES.mono+=	lib/System.Runtime.Serialization.Formatters.Soap.dll
BUILDLINK_FILES.mono+=	lib/System.Security.dll
BUILDLINK_FILES.mono+=	lib/System.ServiceProcess.dll
BUILDLINK_FILES.mono+=	lib/System.Web.Services.dll
BUILDLINK_FILES.mono+=	lib/System.Web.dll
BUILDLINK_FILES.mono+=	lib/System.Windows.Forms.dll
BUILDLINK_FILES.mono+=	lib/System.Xml.dll
BUILDLINK_FILES.mono+=	lib/System.dll
BUILDLINK_FILES.mono+=	lib/corlib.dll
BUILDLINK_FILES.mono+=	lib/libmono-profiler-cov.*
BUILDLINK_FILES.mono+=	lib/libmono.*
BUILDLINK_FILES.mono+=	lib/libmonogc.*
BUILDLINK_FILES.mono+=	lib/pkgconfig/mono.pc

.include "../../devel/glib2/buildlink2.mk"

BUILDLINK_TARGETS+=	mono-buildlink

mono-buildlink: _BUILDLINK_USE

.endif	# MONO_BUILDLINK2_MK
