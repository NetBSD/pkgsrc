# $NetBSD: Makefile,v 1.3 2025/02/04 08:47:25 imil Exp $

DISTNAME=	dinit-0.19.3
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=davmac314/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/davmac314/dinit/
COMMENT=	Service supervision system and init system
LICENSE=	apache-2.0

USE_LANGUAGES=		c++
USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--enable-shutdown

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
