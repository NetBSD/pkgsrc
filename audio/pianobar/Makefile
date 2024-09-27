# $NetBSD: Makefile,v 1.43 2024/09/27 16:50:35 jakllsch Exp $

DISTNAME=	pianobar-2022.04.01
CATEGORIES=	audio net
MASTER_SITES=	https://6xq.net/pianobar/
EXTRACT_SUFX=	.tar.bz2

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
.include "../../multimedia/ffmpeg6/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
