# $NetBSD: Makefile,v 1.19 2020/04/05 16:05:41 bsiegert Exp $

.include "../../meta-pkgs/mate/Makefile.common"

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
