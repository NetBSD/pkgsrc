# $NetBSD: Makefile,v 1.17 2020/05/02 08:03:17 rillig Exp $
#

PKGNAME=	regress-tools-2020.05.02
CATEGORIES=	pkgtools
DISTFILES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Ensure that the tools wrapper works as expected
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}
PLIST_SRC=	# none
REGRESS_TESTS+=	logging shquote

TOOLS_CREATE+=	script-dquot
TOOLS_SCRIPT.script-dquot= \
		echo "hello; world"

TOOLS_CREATE+=	script-backslash
TOOLS_SCRIPT.script-backslash= \
		echo hello\;\ world

# If both of the above tools are properly quoted during logging, the
# semicolon in "hello; world" is never interpreted as a shell command
# delimiter, and this tool is never run.
TOOLS_CREATE+=	world
TOOLS_SCRIPT.world= \
		echo oops

# The script for this example tool contains single quotes, double quotes
# and backslashes to demonstrate that these are properly logged.
TOOLS_CREATE+=	for-loop
TOOLS_SCRIPT.for-loop= \
	printf '%s' "$$0"; \
	for arg in "$$@"; do \
		printf ' <%s>' "$$arg"; \
	done; \
	printf '\n'

# Demonstrates that double quotes in both the TOOLS_ARGS and the actual
# arguments are properly logged.
TOOLS_CREATE+=			path-args-dquot
TOOLS_PATH.path-args-dquot=	echo
TOOLS_ARGS.path-args-dquot=	\" "\"" '"'

# Demonstrates that both the TOOLS_ARGS and the actual arguments are
# properly logged.
TOOLS_CREATE+=		path-args
TOOLS_PATH.path-args=	echo
TOOLS_ARGS.path-args=	" \"'\\$$" "*"

do-build:
.for test in ${REGRESS_TESTS}
	@${ECHO_MSG} "Running testsuite "${test:Q}
	${RUN} cd ${WRKSRC} \
	&& PKGSRCDIR=${PKGSRCDIR} ${SH} ${FILESDIR}/${test:Q}-test.sh
.endfor

.include "../../mk/bsd.pkg.mk"
