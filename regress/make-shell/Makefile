# $NetBSD: Makefile,v 1.1 2020/05/01 19:16:47 rillig Exp $
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

.include "../../mk/bsd.pkg.mk"
