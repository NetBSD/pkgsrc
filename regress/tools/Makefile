# $NetBSD: Makefile,v 1.13 2019/03/23 22:59:11 rillig Exp $
#

DISTNAME=	# not applicable
PKGNAME=	regress-tools-1.2
CATEGORIES=	regress
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Test whether the TOOLS do what I expect
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
PLIST_SRC=	# none
REGRESS_TESTS+=	logging
REGRESS_TESTS+=	awk sed sh sort tar tr
USE_TOOLS+=	awk sed sh sort tar tr

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

do-build:
.for t in ${REGRESS_TESTS}
	${RUN} cd ${WRKSRC};						\
	${ECHO_MSG} "Running testsuite "${t:Q};				\
	${SH} ${FILESDIR}/${t:Q}-test.sh
.endfor

.include "../../mk/bsd.pkg.mk"
