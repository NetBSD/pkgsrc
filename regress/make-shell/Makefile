# $NetBSD: Makefile,v 1.2 2020/05/01 19:28:15 rillig Exp $
#
# This regression test demonstrates which features are supported by the
# shell that is used internally by devel/bmake.  That shell may be
# different from /bin/sh and ${SH} and TOOLS_PLATFORM.sh.
#
# This is most interesting for platforms whose /bin/sh is so broken that
# it is basically unusable, such as SunOS 10 and earlier.

DISTNAME=	make-shell-2020.05.01
CATEGORIES=	regress
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Test features of the shell used by bmake

WRKSRC=		${WRKDIR}
PLIST_SRC=	# none

do-regress:
	# Up to May 2020, shell functions were not used in package
	# Makefiles.  But could they?
	${RUN} func() { :; }; func

	# The Solaris /bin/sh cannot handle these word expansions.
	# Therefore on Solaris, bmake uses /usr/xpg4/bin/sh instead.
	# Make sure that these don't produce a syntax error.
	${RUN} path="1/2/3/4"; one=$${path%%/*}
	${RUN} path="1/2/3/4"; four=$${path##*/}

	# The Solaris /bin/sh exits with an error in this situation,
	# even though there is an "if" around the "cd".
	${RUN} \
	if cd /bddc80cd-760f-46e7-955c-e767772d57f5 2>/dev/null; then	\
		${FAIL_MSG} "cd unexpectedly succeeded";		\
	else								\
		: "That's expected";					\
	fi

.include "../../mk/bsd.pkg.mk"
