# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/01/12 17:15:29 xtraeme Exp $
#
# This Makefile fragment is included by packages that use pnetlib.
#
# This file was created automatically using createbuildlink 2.9.
#

.if !defined(PNETLIB_BUILDLINK2_MK)
PNETLIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			pnetlib
BUILDLINK_DEPENDS.pnetlib?=		pnetlib>=0.6.2
BUILDLINK_PKGSRCDIR.pnetlib?=		../../lang/pnetlib

EVAL_PREFIX+=	BUILDLINK_PREFIX.pnetlib=pnetlib
BUILDLINK_PREFIX.pnetlib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/0.5.1.0/ICSharpCode.SharpZipLib.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/Accessibility.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/DotGNU.Images.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/DotGNU.SSL.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/DotGNU.Terminal.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/I18N.CJK.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/I18N.MidEast.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/I18N.Other.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/I18N.Rare.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/I18N.West.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/I18N.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/ISymWrapper.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/OpenSystem.C.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/System.Configuration.Install.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/System.Design.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/System.Drawing.Postscript.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/System.Drawing.Win32.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/System.Drawing.Xsharp.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/System.Drawing.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/System.EnterpriseServices.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/System.Net.IrDA.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/System.Windows.Forms.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/System.Xml.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/System.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/Xsharp.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/ca/I18N.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/ca/System.Configuration.Install.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/ca/System.Drawing.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/ca/System.Net.IrDA.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/ca/System.Windows.Forms.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/ca/System.Xml.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/ca/System.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/ca/Xsharp.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/ca/mscorlib.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/cstest.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/csunit.exe
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/de/I18N.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/de/System.Configuration.Install.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/de/System.Drawing.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/de/System.Net.IrDA.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/de/System.Windows.Forms.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/de/System.Xml.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/de/System.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/de/Xsharp.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/de/mscorlib.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/ilinstall.exe
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/1.2.3400.0/mscorlib.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/8.0.1000.0/Microsoft.JScript.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/8.0.1000.0/Microsoft.VisualBasic.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/8.0.1000.0/Microsoft.VisualC.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/8.0.1000.0/Microsoft.Vsa.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/8.0.1000.0/ca/Microsoft.VisualBasic.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/8.0.1000.0/cscompmgd.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/8.0.1000.0/de/Microsoft.VisualBasic.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/8.0.1000.0/jsrun.exe
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/Accessibility.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/DotGNU.Images.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/DotGNU.SSL.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/DotGNU.Terminal.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/I18N.CJK.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/I18N.MidEast.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/I18N.Other.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/I18N.Rare.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/I18N.West.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/I18N.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/ICSharpCode.SharpZipLib.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/ISymWrapper.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/Microsoft.JScript.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/Microsoft.VisualBasic.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/Microsoft.VisualC.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/Microsoft.Vsa.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/OpenSystem.C.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/System.Configuration.Install.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/System.Design.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/System.Drawing.Postscript.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/System.Drawing.Win32.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/System.Drawing.Xsharp.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/System.Drawing.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/System.EnterpriseServices.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/System.Net.IrDA.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/System.Windows.Forms.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/System.Xml.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/System.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/Xsharp.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/ca/I18N.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/ca/Microsoft.VisualBasic.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/ca/System.Configuration.Install.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/ca/System.Drawing.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/ca/System.Net.IrDA.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/ca/System.Windows.Forms.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/ca/System.Xml.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/ca/System.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/ca/Xsharp.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/ca/mscorlib.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/cscompmgd.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/cstest.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/csunit.exe
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/de/I18N.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/de/Microsoft.VisualBasic.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/de/System.Configuration.Install.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/de/System.Drawing.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/de/System.Net.IrDA.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/de/System.Windows.Forms.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/de/System.Xml.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/de/System.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/de/Xsharp.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/de/mscorlib.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/ilinstall.exe
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/jsrun.exe
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/libXsharpSupport.*
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/mscorlib.dll

.include "../../lang/pnet/buildlink2.mk"

BUILDLINK_TARGETS+=	pnetlib-buildlink

pnetlib-buildlink: _BUILDLINK_USE

.endif	# PNETLIB_BUILDLINK2_MK
