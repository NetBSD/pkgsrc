# $NetBSD: check-fakehome.mk,v 1.5 2024/01/19 00:42:01 rillig Exp $
#
# This file warns when the package installs files to $HOME.
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
_USER_VARS.check-fakehome=	CHECK_FAKEHOME PKG_DEVELOPER
_USE_VARS.check-fakehome=	FAKEHOMEDIR

.if ${PKG_DEVELOPER:Uno} != "no"
CHECK_FAKEHOME?=		yes
.else
CHECK_FAKEHOME?=		no
.endif

.if ${CHECK_FAKEHOME:tl} == yes
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
