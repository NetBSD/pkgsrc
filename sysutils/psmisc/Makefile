# $NetBSD: Makefile,v 1.10 2001/07/14 07:42:55 jlam Exp $

DISTNAME=		psmisc-20.1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=psmisc/}

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://psmisc.sourceforge.net/
COMMENT=		miscellaneous procfs tools: killall, pidof, and pstree

CONFLICTS+=		pstree-[0-9]*

GNU_CONFIGURE=		# defined
USE_BUILDLINK_ONLY=	# defined

# "make install" doesn't install the link from killall -> pidof.
post-install:
	${RM} -f ${PREFIX}/bin/pidof
	${LN} -f ${PREFIX}/bin/killall ${PREFIX}/bin/pidof

.include "../../devel/libgetopt/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
