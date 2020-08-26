# $NetBSD: Makefile,v 1.23 2020/08/26 21:22:13 jmcneill Exp $

.include "../../meta-pkgs/mate/Makefile.common"

PKGREVISION=	4
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
