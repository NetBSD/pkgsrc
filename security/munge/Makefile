# $NetBSD: Makefile,v 1.18 2018/02/28 09:20:29 wiz Exp $

DISTNAME=	munge-0.5.13
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=dun/}
GITHUB_RELEASE=	${DISTNAME}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	https://dun.github.io/munge/
COMMENT=	Authentication service for creating and validating credentials

USE_TOOLS=	perl pkg-config
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
INSTALLATION_DIRS+=	lib/pkgconfig

OWN_DIRS=	${VARBASE}/lib/munge ${VARBASE}/log/munge ${VARBASE}/run/munge

RCD_SCRIPTS+=	munge

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
