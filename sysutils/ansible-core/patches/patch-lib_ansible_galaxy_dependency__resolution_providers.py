$NetBSD: patch-lib_ansible_galaxy_dependency__resolution_providers.py,v 1.1 2023/01/13 13:48:45 adam Exp $

Support newer resolvelib.
https://github.com/ansible/ansible/pull/79576

--- lib/ansible/galaxy/dependency_resolution/providers.py.orig	2023-01-13 13:17:02.000000000 +0000
+++ lib/ansible/galaxy/dependency_resolution/providers.py
@@ -42,7 +42,7 @@ except ImportError:
 
 # TODO: add python requirements to ansible-test's ansible-core distribution info and remove the hardcoded lowerbound/upperbound fallback
 RESOLVELIB_LOWERBOUND = SemanticVersion("0.5.3")
-RESOLVELIB_UPPERBOUND = SemanticVersion("0.9.0")
+RESOLVELIB_UPPERBOUND = SemanticVersion("0.10.0")
 RESOLVELIB_VERSION = SemanticVersion.from_loose_version(LooseVersion(resolvelib_version))
 
 
@@ -220,7 +220,7 @@ class CollectionDependencyProviderBase(A
             Mapping of identifier, list of named tuple pairs.
             The named tuples have the entries ``requirement`` and ``parent``.
 
-        resolvelib >=0.8.0, <= 0.8.1
+        resolvelib >=0.8.0, <= 0.9.0
 
         :param identifier: The value returned by ``identify()``.
 
