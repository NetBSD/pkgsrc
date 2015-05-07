# $NetBSD: Makefile,v 1.3 2015/05/07 14:07:02 mef Exp $

DISTNAME=	libebur128-1.0.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=jiixyj/}
GITHUB_PROJECT=	libebur128
GITHUB_TAG=	${DISTNAME:S/libebur128-/v/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jiixyj/libebur128/
COMMENT=	EBU R128 loudness standard implementation
LICENSE=	mit

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

.include "../../audio/speex/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
