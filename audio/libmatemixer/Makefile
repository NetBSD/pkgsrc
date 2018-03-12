# $NetBSD: Makefile,v 1.8 2018/03/12 11:16:03 wiz Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	libmatemixer-${VERSION}
PKGREVISION=	3
CATEGORIES=	audio

COMMENT=	MATE audio mixer

.include "../../mk/oss.buildlink3.mk"

PLIST_VARS+=		oss
.if ${OSS_TYPE} != "none"
CONFIGURE_ARGS+=	--enable-oss
PLIST.oss=		yes
.endif

.include "../../mk/bsd.pkg.mk"
