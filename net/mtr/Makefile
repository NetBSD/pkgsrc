# $NetBSD: Makefile,v 1.9 2000/06/14 02:10:58 hubertf Exp $
# $FreeBSD: ports/net/mtr/Makefile,v 1.16 1999/10/28 08:06:00 mharo Exp $

DISTNAME=	mtr-0.42
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/ \
		http://www.giovannelli.it/~gmarco/files/

MAINTAINER=	sommerfeld@netbsd.org
HOMEPAGE=	http://www.bitwizard.nl/mtr/

DEPENDS+=	gtk+>=1.2.7:../../x11/gtk

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV+= CPPFLAGS=-I${PREFIX}/include

.include "../../mk/bsd.prefs.mk"
GOOD_CURSES=	1.4[Y-Z] 1.4Z[A-Z] 1.[5-9]*

.for PATTERN in ${GOOD_CURSES}
.if ${OS_VERSION:M${PATTERN}} != ""
CURSES_GOOD?=	# defined
.endif
.endfor

.if defined(CURSES_GOOD)
# hack to use curses even if ncurses are also installed
pre-configure:
.for FILE in configure configure.in
	cd ${WRKSRC}; ${SED} "s/ncurses/curses/" < ${FILE} \
		> ${FILE}.patched; ${MV} ${FILE}.patched ${FILE}
.endfor
	${CHMOD} 755 ${WRKSRC}/configure
.else
DEPENDS+=	ncurses>=4.2:../../devel/ncurses
.endif

do-install:
	${INSTALL} -c -s -m 4755 -o root -g wheel ${WRKSRC}/mtr ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/mtr.8 ${PREFIX}/man/man8

post-install:
	@${ECHO} ""
	@${ECHO} "${PREFIX}/sbin/mtr is setuid \"root\" "
	@${ECHO} ""
	@${ECHO} "Please read about potential security issues"
	@${ECHO} "in file ${WRKSRC}/SECURITY (not installed)"
	@${ECHO} ""

.include "../../mk/bsd.pkg.mk"
