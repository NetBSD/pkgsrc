# $NetBSD: Makefile,v 1.27 2023/01/03 17:36:45 wiz Exp $

PKGREVISION= 1
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	libmatemixer-${VERSION}
CATEGORIES=	audio

COMMENT=	MATE audio mixer

.include "../../mk/oss.buildlink3.mk"

PLIST_VARS+=		oss
.if ${OSS_TYPE} != "none"
CONFIGURE_ARGS+=	--enable-oss
PLIST.oss=		yes
.endif

.include "../../mk/bsd.pkg.mk"
