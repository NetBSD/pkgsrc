# $NetBSD: Makefile,v 1.8 2001/06/18 10:55:03 jlam Exp $

DISTNAME=		psmisc-20.1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=psmisc/}

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://psmisc.sourceforge.net/
COMMENT=		miscellaneous procfs tools: killall, pidof, and pstree

CONFLICTS+=		pstree-[0-9]*

GNU_CONFIGURE=		# defined

# Don't match tgetstr() to libncurses, but force fall-through to libtermcap.
CONFIGURE_ENV+=		ac_lib_var_ncurses_tgetstr=no

.include "../../devel/libgetopt/buildlink.mk"

# "make install" doesn't install the link from killall -> pidof.
post-install:
	${RM} -f ${PREFIX}/bin/pidof
	${LN} -f ${PREFIX}/bin/killall ${PREFIX}/bin/pidof

.include "../../mk/bsd.pkg.mk"
