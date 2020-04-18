# $NetBSD: Makefile,v 1.20 2020/04/18 12:22:45 bsiegert Exp $

.include "../../meta-pkgs/mate/Makefile.common"

PKGREVISION=	1
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
