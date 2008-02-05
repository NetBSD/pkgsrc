# $NetBSD: check-fakehome.mk,v 1.2 2008/02/05 11:17:00 tnn Exp $
#
# This file checks that the package does not install files to $HOME.
#
# User-settable variables:
#
# CHECK_FAKEHOME
#	Specifies whether the check should be run at all.
#
#	Possible values: yes, no.
#
#	Default value: yes for PKG_DEVELOPER, no otherwise.
#
# Package-settable variables:
#

_VARGROUPS+=			check-fakehome
_USER_VARS.check-fakehome=	CHECK_FAKEHOME
_PKG_VARS.check-fakehome=	# None for now. One might be added to override
#				  the test if the fakehome test is made fatal.

.if defined(PKG_DEVELOPER)
CHECK_FAKEHOME?=		yes
.else
CHECK_FAKEHOME?=		no
.endif

.if ${CHECK_FAKEHOME:M[Yy][Ee][Ss]}
privileged-install-hook: _check-fakehome
.endif

_check-fakehome: .PHONY
	${RUN} if [ `ls -a ${FAKEHOMEDIR:Q} | ${AWK} 			\
		'{if ($$0 != "." && $$0 != "..") {x=1; exit}}		\
		END {print x + 0}'					\
	` = 1 ]; then							\
		${WARNING_MSG} "[check-fakehome.mk] fake home directory not empty:"; \
		find ${FAKEHOMEDIR} -print | ${SED} 's/^/	/';	\
		exit 0;							\
	fi
