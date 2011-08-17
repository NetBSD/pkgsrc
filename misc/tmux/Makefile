# $NetBSD: Makefile,v 1.15 2011/08/17 16:57:18 jmmv Exp $

DISTNAME=	tmux-1.5
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tmux/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tmux.sourceforge.net/
COMMENT=	BSD-licensed terminal multiplexer (GNU Screen alternative)
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TERMINFO=	yes

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
