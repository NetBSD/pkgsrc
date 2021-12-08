# $NetBSD: Makefile,v 1.24 2021/12/08 16:03:15 adam Exp $

.include "../../meta-pkgs/mate/Makefile.common"

PKGREVISION=	5
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
