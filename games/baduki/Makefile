# $NetBSD: Makefile,v 1.24 2002/09/21 12:40:10 jlam Exp $

DISTNAME=	baduki-0.2.9
CATEGORIES=	games
MASTER_SITES=	http://soback.kornet21.net/~artist/baduk/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://soback.kornet21.net/~artist/baduk/baduki.html
COMMENT=	Go playing program based on xamigo

BUILD_USES_MSGFMT=	YES
USE_BUILDLINK2=		YES
USE_X11=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-included-gettext

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
