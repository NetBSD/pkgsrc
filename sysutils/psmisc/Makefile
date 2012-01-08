# $NetBSD: Makefile,v 1.25 2012/01/08 03:47:51 sbd Exp $

DISTNAME=		psmisc-20.1
CATEGORIES=		sysutils
PKGREVISION=		2
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=psmisc/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://psmisc.sourceforge.net/
COMMENT=		Miscellaneous procfs tools: killall, pidof, and pstree

CONFLICTS+=		pstree<=2.16

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
LIBS+=			${BUILDLINK_LDADD.getopt}

# "make install" doesn't install the link from killall -> pidof.
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/pidof
	${LN} -f ${DESTDIR}${PREFIX}/bin/killall ${DESTDIR}${PREFIX}/bin/pidof

.include "../../mk/termcap.buildlink3.mk"
# XXX configure only tests for ncurses and termcap.
.if empty(BUILDLINK_TREE:Mncurses)
BUILDLINK_TRANSFORM+=	l:ncurses:curses
.endif
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
