# $NetBSD: uac-manifest.mk,v 1.1 2013/02/10 13:04:08 obache Exp $
#
# This file generate manifest files for Windows.
# For Windows Vista or later, executable files including special keywords
# (install, update, patch, and so on) in its name are expected as requireing
# privileged permissions by default (UAC).
# If not, it must be specified with manifest file, or it will be failed to
#  execute as "Permission denied".
#
# Package-settable variables:
#
# UAC_REQD_EXECS
#	A list of files requireing manifest file for UAC.
#	Paths are relative to PREFIX.
#
#	Default value: not defined
#

GENERATE_PLIST+=	${UAC_MANIFEST_GENERATE_PLIST}
UAC_MANIFEST_GENERATE_PLIST= \
	${ECHO} "@comment The following lines are automatically generated." && \
	( cd ${DESTDIR}${PREFIX}; \
	  for file in  ${UAC_REQD_EXECS}; do \
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