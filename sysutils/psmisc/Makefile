# $NetBSD: Makefile,v 1.6 2001/04/24 16:59:34 jlam Exp $

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

# killall uses getopt_long(), which only appeared since the NetBSD 1.5 release.
.if !exists(/usr/include/getopt.h)
DEPENDS+=		libgetopt>=1.3:../../devel/libgetopt
EVAL_PREFIX+=		GETOPTDIR=libgetopt
CPPFLAGS+=		-I${GETOPTDIR}/include
LDFLAGS+=		-Wl,-R${GETOPTDIR} -L${GETOPTDIR} -lgetopt
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
.endif

# "make install" doesn't install the link from killall -> pidof.
post-install:
	${RM} -f ${PREFIX}/bin/pidof
	${LN} -f ${PREFIX}/bin/killall ${PREFIX}/bin/pidof

.include "../../mk/bsd.pkg.mk"
