# $NetBSD: Makefile,v 1.19 2001/06/28 22:22:32 zuntum Exp $

DISTNAME=	baduki-0.2.9
CATEGORIES=	games
MASTER_SITES=	http://soback.kornet21.net/~artist/baduk/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://soback.kornet21.net/~artist/baduk/baduki.html
COMMENT=	Go playing program based on xamigo

USE_BUILDLINK_ONLY=	YES
USE_CONFIG_WRAPPER=	YES
USE_X11=		YES
GNU_CONFIGURE=		YES
BUILD_USES_MSGFMT=	YES

CONFIGURE_ARGS+=	--without-included-gettext

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
