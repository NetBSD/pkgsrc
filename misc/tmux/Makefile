# $NetBSD: Makefile,v 1.8 2010/02/22 19:07:41 drochner Exp $

DISTNAME=	tmux-1.1
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tmux/}

MAINTAINER=	hasso@NetBSD.org
HOMEPAGE=	http://tmux.sourceforge.net/
COMMENT=	BSD-licensed terminal multiplexer (GNU Screen alternative)
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
