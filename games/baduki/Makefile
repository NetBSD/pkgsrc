# $NetBSD: Makefile,v 1.32 2004/10/03 00:14:42 tv Exp $

DISTNAME=	baduki-0.2.9
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://soback.kornet21.net/~artist/baduk/

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://soback.kornet21.net/~artist/baduk/baduki.html
COMMENT=	Go playing program based on xamigo

BUILD_USES_MSGFMT=	# defined

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	# defined
USE_X11=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--without-included-gettext

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
