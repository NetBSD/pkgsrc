# $NetBSD: Makefile,v 1.5 2020/01/26 17:31:44 rillig Exp $
#

DISTNAME=	mkcue_1.orig
PKGNAME=	mkcue-2.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/m/mkcue/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://packages.debian.org/source/stable/mkcue
COMMENT=	Generates a CUE sheet from a CD
LICENSE=	gnu-lgpl-v2

WRKSRC=		${WRKDIR}/mkcue-1.orig
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile

INSTALLATION_DIRS=	bin

post-extract:
	${CP} ${FILESDIR}/mb_dragonfly.cpp ${WRKSRC}/osdep
	${CP} ${FILESDIR}/mb_dragonfly.h ${WRKSRC}/osdep

.include "../../mk/bsd.pkg.mk"
