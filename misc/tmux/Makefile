# $NetBSD: Makefile,v 1.19 2012/10/08 09:57:38 asau Exp $

DISTNAME=	tmux-1.6
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tmux/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tmux.sourceforge.net/
COMMENT=	BSD-licensed terminal multiplexer (GNU Screen alternative)
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TERMINFO=	yes

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"
.if !empty(MACHINE_PLATFORM:MSunOS-5.1[0-9]-*) && \
    !empty(CC_VERSION:Mgcc-4.[6-9].*)
BUILDLINK_TRANSFORM+=   rename:-D_XPG4_2:-D_XPG6
.endif

.include "../../devel/libevent/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=1.1b
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
