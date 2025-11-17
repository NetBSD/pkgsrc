# $NetBSD: Makefile,v 1.26 2025/11/17 11:00:51 wiz Exp $

DISTNAME=	lpairs-1.0.5
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lgames.sourceforge.net/
COMMENT=	Memory game matching pairs of cards

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--disable-sdltest
LDFLAGS+=		${BUILDLINK_LDADD.gettext}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
