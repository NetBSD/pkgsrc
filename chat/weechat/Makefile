# $NetBSD: Makefile,v 1.7 2006/02/05 23:08:26 joerg Exp $
#

DISTNAME=	weechat-0.0.6
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	http://weechat.flashtux.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://weechat.flashtux.org/
COMMENT=	Lightweight and user friendly curses based IRC client

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_USES_MSGFMT=	yes

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INCOMPAT_CURSES+=	NetBSD-1.*-*

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
