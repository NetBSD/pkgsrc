# $NetBSD: Makefile,v 1.2 2003/01/24 00:16:10 wiz Exp $
#

DISTNAME=	gtetrinet-0.4.4
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtetrinet/}

MAINTAINER=	bmeurer@fwdn.de
HOMEPAGE=	http://gtetrinet.sourceforge.net/
COMMENT=	Multiplayer tetris game

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../mk/bsd.prefs.mk"

# IPv6 support
.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
