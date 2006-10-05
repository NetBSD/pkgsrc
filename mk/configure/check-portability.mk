# $NetBSD: check-portability.mk,v 1.4 2006/10/05 10:52:40 rillig Exp $
#
# This file contains some checks that are applied to the configure
# scripts to check for certain constructs that are known to cause
# problems on some platforms.
#
# The following variables may be set by the pkgsrc user in mk.conf:
#
# CHECK_PORTABILITY: YesNo
#	Whether to enable some portability checks for the configure
#	scripts before they are run.
#
#	Default value: yes for PKG_DEVELOPERs, no otherwise.
#
# The following variables may be set by the package:
#
# SKIP_PORTABILITY_CHECK: YesNo
#	Whether the above checks should be skipped for the current
#	package.
#
#	Default value: no
#

.if defined(PKG_DEVELOPER) && !empty(PKG_DEVELOPER:M[Yy][Ee][Ss])
CHECK_PORTABILITY?=		yes
.endif
CHECK_PORTABILITY?=		no
SKIP_PORTABILITY_CHECK?=	no

.if ${CHECK_PORTABILITY:M[Yy][Ee][Ss]} != "" && \
    ${SKIP_PORTABILITY_CHECK:M[Yy][Ee][Ss]} == ""
do-configure-pre-hook: _configure-check-for-test
.endif
.PHONY: _configure-check-for-test
_configure-check-for-test:
	@${STEP_MSG} "Checking for \"test ... == ...\" in configure scripts"
.for d in ${CONFIGURE_DIRS}
	${_PKG_SILENT}${_PKG_DEBUG}set -e;				\
	cd ${WRKSRC}; cd ${d};						\
	case `sed '1q' < ${CONFIGURE_SCRIPT}` in			\
	"#!"*"/bin/sh")							\
		found=no;						\
		while read line; do					\
			set args $$line; shift;				\
			while [ $$# -ge 3 ]; do				\
				if [ ":$$1" = ":test" ] && [ ":$$3" = ":==" ]; then \
					found=yes;			\
					${ERROR_MSG} "[configure.mk] $$line"; \
				elif [ ":$$1" = ":#" ]; then		\
					break;				\
				fi;					\
				shift;					\
			done;						\
			if [ "$$found" = "yes" ]; then			\
				${ERROR_MSG} "[configure.mk] Found test ... == ... in configure script."; \
				exit 1;					\
			fi;						\
		done < ${CONFIGURE_SCRIPT};				\
		;;							\
	esac
.endfor
