$NetBSD: patch-src_core_OCIOYaml.cpp,v 1.2 2021/09/10 12:21:57 nia Exp $

Description: Fix build with yaml-cpp 0.6
 One of the changes in yaml-cpp 0.6 was the replacement of some inline
 virtual functions with out-of-line virtual functions, to ensure a
 single definition of the relevant vtable.
 .
 Unfortunately, OpenColorIO forward-declares these classes with a different
 GCC visibility attribute. Now that the key function for the vtables is
 not inlined into code using yaml-cpp.h that breaks link-time resolution of
 the vtables.
Author: Christopher James Halse Rogers <christopher.halse.rogers@canonical.com>
Bug: https://github.com/imageworks/OpenColorIO/issues/517

--- src/core/OCIOYaml.cpp.orig	2019-03-28 05:12:57.000000000 +0000
+++ src/core/OCIOYaml.cpp
@@ -30,43 +30,6 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 
 #include <OpenColorIO/OpenColorIO.h>
 
-#ifndef WIN32
-
-// fwd declare yaml-cpp visibility
-#pragma GCC visibility push(hidden)
-namespace YAML {
-    class Exception;
-    class BadDereference;
-    class RepresentationException;
-    class EmitterException;
-    class ParserException;
-    class InvalidScalar;
-    class KeyNotFound;
-    template <typename T> class TypedKeyNotFound;
-    template <> class TypedKeyNotFound<OCIO_NAMESPACE::ColorSpace>;
-    template <> class TypedKeyNotFound<OCIO_NAMESPACE::Config>;
-    template <> class TypedKeyNotFound<OCIO_NAMESPACE::Exception>;
-    template <> class TypedKeyNotFound<OCIO_NAMESPACE::GpuShaderDesc>;
-    template <> class TypedKeyNotFound<OCIO_NAMESPACE::ImageDesc>;
-    template <> class TypedKeyNotFound<OCIO_NAMESPACE::Look>;
-    template <> class TypedKeyNotFound<OCIO_NAMESPACE::Processor>;
-    template <> class TypedKeyNotFound<OCIO_NAMESPACE::Transform>;
-    template <> class TypedKeyNotFound<OCIO_NAMESPACE::AllocationTransform>;
-    template <> class TypedKeyNotFound<OCIO_NAMESPACE::CDLTransform>;
-    template <> class TypedKeyNotFound<OCIO_NAMESPACE::ColorSpaceTransform>;
-    template <> class TypedKeyNotFound<OCIO_NAMESPACE::DisplayTransform>;
-    template <> class TypedKeyNotFound<OCIO_NAMESPACE::ExponentTransform>;
-    template <> class TypedKeyNotFound<OCIO_NAMESPACE::FileTransform>;
-    template <> class TypedKeyNotFound<OCIO_NAMESPACE::GroupTransform>;
-    template <> class TypedKeyNotFound<OCIO_NAMESPACE::LogTransform>;
-    template <> class TypedKeyNotFound<OCIO_NAMESPACE::LookTransform>;
-    template <> class TypedKeyNotFound<OCIO_NAMESPACE::MatrixTransform>;
-    template <> class TypedKeyNotFound<OCIO_NAMESPACE::TruelightTransform>;
-}
-#pragma GCC visibility pop
-
-#endif
-
 #ifdef WIN32
 #pragma warning( push )
 #pragma warning( disable: 4146 )
@@ -1439,11 +1402,7 @@ OCIO_NAMESPACE_ENTER
             
             // check profile version
             int profile_version = 0;
-#ifdef OLDYAML
-            if(node.FindValue("ocio_profile_version") == NULL)
-#else
-            if(node["ocio_profile_version"] == NULL)
-#endif
+            if(!node["ocio_profile_version"].IsDefined())
             {
                 std::ostringstream os;
                 os << "The specified file ";
