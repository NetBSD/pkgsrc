# $NetBSD: Makefile,v 1.4 2026/06/24 14:54:24 schmonz Exp $

DISTNAME=		bfs-4.1.3
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=tavianator/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/tavianator/bfs/
COMMENT=		Breadth-first version of the UNIX find command
LICENSE=		0-clause-bsd

USE_LANGUAGES=		c
USE_CC_FEATURES=	c99
USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-release
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--mandir=${PREFIX:Q}/${PKGMANDIR:Q}
CONFIGURE_ARGS+=	--without-libacl
CONFIGURE_ARGS+=	--without-libcap
CONFIGURE_ARGS+=	--without-libselinux
CONFIGURE_ARGS+=	--without-liburing
CONFIGURE_ARGS+=	--without-oniguruma

INSTALLATION_DIRS+=	bin ${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
