# $NetBSD: Makefile,v 1.25 2002/11/30 14:45:33 grant Exp $

DISTNAME=	baduki-0.2.9
CATEGORIES=	games
MASTER_SITES=	http://soback.kornet21.net/~artist/baduk/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://soback.kornet21.net/~artist/baduk/baduki.html
COMMENT=	Go playing program based on xamigo

BUILD_USES_MSGFMT=	# defined
USE_BUILDLINK2=		# defined
USE_X11=		# defined

GNU_CONFIGURE=		# defined
USE_PKGLOCALEDIR=	# defined
CONFIGURE_ARGS+=	--without-included-gettext

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
