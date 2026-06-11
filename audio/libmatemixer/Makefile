# $NetBSD: Makefile,v 1.42 2026/06/11 07:16:43 wiz Exp $

PKGREVISION= 13
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
