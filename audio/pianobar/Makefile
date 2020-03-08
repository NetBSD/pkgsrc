# $NetBSD: Makefile,v 1.23 2020/03/08 16:48:48 wiz Exp $

DISTNAME=	pianobar-2019.02.14
PKGREVISION=	3
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
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
