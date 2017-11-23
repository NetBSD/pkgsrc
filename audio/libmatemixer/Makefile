# $NetBSD: Makefile,v 1.7 2017/11/23 17:19:48 wiz Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	libmatemixer-${VERSION}
PKGREVISION=	2
CATEGORIES=	audio

COMMENT=	MATE audio mixer

.include "../../mk/oss.buildlink3.mk"

PLIST_VARS+=		oss
.if ${OSS_TYPE} != "none"
CONFIGURE_ARGS+=	--enable-oss
PLIST.oss=		yes
.endif

.include "../../mk/bsd.pkg.mk"
