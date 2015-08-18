# $NetBSD: Makefile,v 1.24 2015/08/18 07:31:16 wiz Exp $
#

DISTNAME=	tn5250-0.12.51
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.blarg.net/users/mmadore/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.linux-sna.org/software/5250/
COMMENT=	Implementation of the IBM 5250 telnet protocol

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

LDFLAGS.SunOS+=	-lsocket -lnsl -lxnet

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
