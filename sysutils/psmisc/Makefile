# $NetBSD: Makefile,v 1.14 2002/09/27 16:24:41 agc Exp $

DISTNAME=		psmisc-20.1
CATEGORIES=		sysutils
PKGREVISION=		1
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=psmisc/}

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://psmisc.sourceforge.net/
COMMENT=		miscellaneous procfs tools: killall, pidof, and pstree

CONFLICTS+=		pstree<=2.16

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
LIBS+=			${LIBGETOPT}

# "make install" doesn't install the link from killall -> pidof.
post-install:
	${RM} -f ${PREFIX}/bin/pidof
	${LN} -f ${PREFIX}/bin/killall ${PREFIX}/bin/pidof

.include "../../devel/libgetopt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
