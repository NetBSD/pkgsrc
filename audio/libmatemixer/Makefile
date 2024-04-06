# $NetBSD: Makefile,v 1.33 2024/04/06 08:04:49 wiz Exp $

PKGREVISION= 4
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	libmatemixer-${VERSION:R}.1
CATEGORIES=	audio

COMMENT=	MATE audio mixer

.include "../../mk/oss.buildlink3.mk"

PLIST_VARS+=		oss
.if ${OSS_TYPE} != "none"
CONFIGURE_ARGS+=	--enable-oss
PLIST.oss=		yes
.endif

.include "../../mk/bsd.pkg.mk"
