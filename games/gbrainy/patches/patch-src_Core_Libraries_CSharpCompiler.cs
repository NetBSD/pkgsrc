$NetBSD: patch-src_Core_Libraries_CSharpCompiler.cs,v 1.1 2013/05/29 11:13:41 wiz Exp $

Fix
./Libraries/CSharpCompiler.cs(48,20): error CS1729: The type `Mono.CSharp.Report' does not contain a constructor that takes `1' arguments
/usr/pkg/lib/mono/4.0/Mono.CSharp.dll (Location of the symbol related to previous error)
./Libraries/CSharpCompiler.cs(50,16): error CS1729: The type `Mono.CSharp.Evaluator' does not contain a constructor that takes `2' arguments
/usr/pkg/lib/mono/4.0/Mono.CSharp.dll (Location of the symbol related to previous error)
from
http://svnweb.freebsd.org/ports/head/games/gbrainy/files/patch-CSharpCompiler.cs?revision=297313&view=markup

--- src/Core/Libraries/CSharpCompiler.cs.orig	2011-07-19 18:22:43.000000000 +0000
+++ src/Core/Libraries/CSharpCompiler.cs
@@ -44,10 +44,7 @@ namespace gbrainy.Core.Libraries
 
 		public CSharpCompiler ()
 		{
-			CompilerSettings settings = new CompilerSettings ();
-			Report report = new Report (new NullReportPrinter ());
-
-			evaluator = new Evaluator (settings, report);
+			evaluator = new Evaluator (new CompilerContext (new CompilerSettings (), new NullReportPrinter ()));
 		}
 
 		public void EvaluateCode (string code)
