# $NetBSD: Makefile,v 1.12 2001/06/11 06:34:46 jlam Exp $
# $FreeBSD: ports/net/mtr/Makefile,v 1.16 1999/10/28 08:06:00 mharo Exp $

DISTNAME=	mtr-0.42
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/ \
		http://www.giovannelli.it/~gmarco/files/

MAINTAINER=	sommerfeld@netbsd.org
HOMEPAGE=	http://www.bitwizard.nl/mtr/
COMMENT=	Traceroute and ping in a single graphical network diagnostic tool

DEPENDS+=	gtk+>=1.2.7:../../x11/gtk

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_CURSES=	yes
# next line only needed if ncurses are also installed
REPLACE_NCURSES=	configure configure.in
CPPFLAGS+=	-I${PREFIX}/include

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
