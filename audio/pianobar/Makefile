# $NetBSD: Makefile,v 1.42 2024/05/29 16:31:24 adam Exp $

DISTNAME=	pianobar-2020.04.05
PKGREVISION=	18
CATEGORIES=	audio net
MASTER_SITES=	${MASTER_SITE_GITHUB:=PromyLOPh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://6xq.net/pianobar/
COMMENT=	Console client for Pandora
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c99
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

.include "../../audio/libao/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
