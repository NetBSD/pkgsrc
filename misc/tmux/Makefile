# $NetBSD: Makefile,v 1.4 2009/06/08 19:26:29 hasso Exp $

DISTNAME=	tmux-0.8
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tmux/}

MAINTAINER=	hasso@NetBSD.org
HOMEPAGE=	http://tmux.sourceforge.net/
COMMENT=	BSD-licensed terminal multiplexer (GNU Screen alternative)
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
USE_NCURSES=	yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
