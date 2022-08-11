# $NetBSD: Makefile,v 1.25 2022/08/11 05:08:03 gutteridge Exp $

.include "../../meta-pkgs/mate/Makefile.common"

PKGREVISION=	6
DISTNAME=	libmatemixer-${VERSION:R}.0
CATEGORIES=	audio

COMMENT=	MATE audio mixer

.include "../../mk/oss.buildlink3.mk"

PLIST_VARS+=		oss
.if ${OSS_TYPE} != "none"
CONFIGURE_ARGS+=	--enable-oss
PLIST.oss=		yes
.endif

.include "../../mk/bsd.pkg.mk"
