# $NetBSD: Makefile,v 1.24 2020/03/22 09:26:34 nia Exp $

DISTNAME=	lpairs-1.0.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	Memory game matching pairs of cards

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--disable-sdltest
LDFLAGS+=		${BUILDLINK_LDADD.gettext}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
