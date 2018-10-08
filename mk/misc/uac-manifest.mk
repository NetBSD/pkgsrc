# $NetBSD: uac-manifest.mk,v 1.3 2018/10/08 20:35:00 rillig Exp $
#
# This file generates manifest files for Windows.
#
# For Windows Vista or later, executable files including special keywords
# (install, update, patch, and so on) in its name are expected to require
# privileged permissions by default (UAC). If not, it must be specified
# with a manifest file, or it will fail to execute with a "Permission
# denied" error message.
#
# Package-settable variables:
#
# UAC_REQD_EXECS
#	A list of files requiring manifest file for UAC.
#	Paths are relative to PREFIX.
#
#	Default value: not defined
#

GENERATE_PLIST+=	${UAC_MANIFEST_GENERATE_PLIST}
UAC_MANIFEST_GENERATE_PLIST= \
	${ECHO} "@comment The following lines are automatically generated." && \
	( cd ${DESTDIR}${PREFIX}; \
	  for file in ${UAC_REQD_EXECS}; do \
	      ${TEST} $${file} -ef $${file}.exe && file=$${file}.exe; \
	      ${ECHO} $${file}.manifest; \
	  done)

.PHONY: generate-uac-manifests
post-install: generate-uac-manifests
generate-uac-manifests:
.for file in ${UAC_REQD_EXECS}
	${RUN} progname=`basename ${file} .exe`; \
	filename=${file}; \
	cd ${DESTDIR}${PREFIX}; \
	${TEST} ${file} -ef ${file}.exe && filename=${file}.exe; \
	${SED} -e s,@PKGNAME@,${PKGBASE}, -e s,@PROGNAME@,$${progname}, \
		${PKGSRCDIR}/mk/misc/uac-manifest \
		> $${filename}.manifest
.endfor
