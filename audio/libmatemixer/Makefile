# $NetBSD: Makefile,v 1.21 2020/08/17 20:18:08 leot Exp $

.include "../../meta-pkgs/mate/Makefile.common"

PKGREVISION=	2
DISTNAME=	libmatemixer-${VERSION:R}.0
CATEGORIES=	audio

COMMENT=	MATE audio mixer

.include "../../mk/oss.buildlink3.mk"

# see https://github.com/mate-desktop/libmatemixer/issues/28
PLIST_VARS+=		oss
#.if ${OSS_TYPE} != "none"
#CONFIGURE_ARGS+=	--enable-oss
#PLIST.oss=		yes
#.endif

.include "../../mk/bsd.pkg.mk"
