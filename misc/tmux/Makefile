# $NetBSD: Makefile,v 1.14 2011/02/28 14:52:57 wiz Exp $

DISTNAME=	tmux-1.4
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tmux/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tmux.sourceforge.net/
COMMENT=	BSD-licensed terminal multiplexer (GNU Screen alternative)
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	yes
USE_TERMINFO=	yes

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
