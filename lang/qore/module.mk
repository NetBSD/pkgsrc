# $NetBSD: module.mk,v 1.2 2016/07/20 11:58:40 nros Exp $
#
# This file should be included in the makefile of packages that install
# Qore modules.
#
# PLIST variables:
#
# QORE_VERSION 		 To be used by packages that install files in
# 			 ${QORE_MODULE_DIR}/${QORE_VERSION}/
#
# QORE_MODULE_API	 This should be used by packages that install
# 			 modules that uses the compatible module api
#			 version.
#
# QORE_MODULE_DIR	 The directory where binary modules are
#			 installed relative to ${PREFIX}.
#
#
# QORE_LATEST_MODULE_API This should be used by packages that install
#			 modules that uses the latest module api
#			 version.
#
# QORE_USER_MODULE_DIR	 The directory where users modules(qm files) are
#			 installed relative to ${PREFIX}.
#
#
#

qore-module: post-install .PHONY
qore-version=qore --short-version | ${SED} -e s/-.*//
qore-module-api=qore --module-api
qore-module-dir=qore --module-dir
qore-latest-module-api=qore --latest-module-api
qore-user-module-dir=qore --user-module-dir
PLIST_SUBST+=QORE_VERSION="${qore-version:sh}"
PLIST_SUBST+=QORE_MODULE_API="${qore-module-api:sh}"
PLIST_SUBST+=QORE_MODULE_DIR="${qore-module-dir:sh:C,^${PREFIX}/,,W}"
PLIST_SUBST+=QORE_LATEST_MODULE_API="${qore-latest-module-api:sh}"
PLIST_SUBST+=QORE_USER_MODULE_DIR="${qore-user-module-dir:sh:C,^${PREFIX}/,,W}"
