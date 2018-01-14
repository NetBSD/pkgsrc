# $NetBSD: Makefile,v 1.26 2018/01/14 10:41:37 wiz Exp $

DISTNAME=	tn5250-0.12.51
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.blarg.net/users/mmadore/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.linux-sna.org/software/5250/
COMMENT=	Implementation of the IBM 5250 telnet protocol

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
FAKE_NCURSES=	yes

LDFLAGS.SunOS+=	-lsocket -lnsl -lxnet

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
