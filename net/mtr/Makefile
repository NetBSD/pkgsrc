# $NetBSD: Makefile,v 1.6 2000/03/17 14:22:49 tron Exp $
# $FreeBSD: ports/net/mtr/Makefile,v 1.16 1999/10/28 08:06:00 mharo Exp $

DISTNAME=	mtr-0.42
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/ \
		http://www.giovannelli.it/~gmarco/files/

MAINTAINER=	sommerfeld@netbsd.org
HOMEPAGE=	http://www.bitwizard.nl/mtr/

DEPENDS+=	gtk+>=1.2.7:../../x11/gtk
# not needed in current as of some time before 1999/12/1, but 
# needed for 1.4.x, so just use ncurses..
DEPENDS+=	ncurses>=4.2:../../devel/ncurses

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV+= CPPFLAGS=-I${PREFIX}/include

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
