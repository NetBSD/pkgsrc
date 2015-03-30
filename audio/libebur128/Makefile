# $NetBSD: Makefile,v 1.2 2015/03/30 11:53:49 wiz Exp $

DISTNAME=	v1.0.1
PKGNAME=	${DISTNAME:S/v/libebur128-/}
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/jiixyj/libebur128/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jiixyj/libebur128/
COMMENT=	EBU R128 loudness standard implementation
LICENSE=	mit

DIST_SUBDIR=	libebur128

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

.include "../../audio/speex/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
