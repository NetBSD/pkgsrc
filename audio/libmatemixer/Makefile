# $NetBSD: Makefile,v 1.37 2024/12/27 08:19:21 wiz Exp $

PKGREVISION= 8
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
