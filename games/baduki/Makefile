# $NetBSD: Makefile,v 1.36 2006/02/05 23:09:12 joerg Exp $

DISTNAME=	baduki-0.2.9
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://soback.kornet21.net/~artist/baduk/

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://soback.kornet21.net/~artist/baduk/baduki.html
COMMENT=	Go playing program based on xamigo

BUILD_USES_MSGFMT=	yes

USE_PKGLOCALEDIR=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-included-gettext

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
