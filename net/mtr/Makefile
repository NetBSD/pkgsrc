# $NetBSD: Makefile,v 1.2 1999/12/04 16:50:10 sommerfeld Exp $
#
# New ports collection makefile for:   mtr
# Version required:    0.41
# Date created:        12 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD: ports/net/mtr/Makefile,v 1.16 1999/10/28 08:06:00 mharo Exp $
#

DISTNAME=	mtr-0.41
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/ \
		http://www.giovannelli.it/~gmarco/files/

MAINTAINER=	sommerfeld@netbsd.org
HOMEPAGE=	http://www.bitwizard.nl/mtr/

# not needed in current as of some time before 1999/12/1, but 
# needed for 1.4.x, so just use ncurses..
DEPENDS+=	ncurses-4.2:../../devel/ncurses

#.if defined(USE_GTK)
#USE_XLIB=	yes
#LIB_DEPENDS=    gtk12.2:../../x11-toolkits/gtk12
#CONFIGURE_ENV+=	GTK_CONFIG="${X11BASE}/bin/gtk12-config"
#.endif

GNU_CONFIGURE=	yes
MAN8=	mtr.8
CONFIGURE_ENV+= CPPFLAGS=-I${PREFIX}/include

#pre-patch:
#.if !defined(USE_GTK)
#	@${ECHO} ""
#	@${ECHO} "If you want to compile with GTK support,"
#	@${ECHO} "hit Ctrl-C right now and use \"make USE_GTK=yes\" "
#	@${ECHO} ""
#CONFIGURE_ARGS+=--with-gtk-prefix=/nopath
#.endif

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
