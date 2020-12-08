# $NetBSD: Makefile,v 1.18 2020/12/08 11:32:00 nia Exp $
#

DISTNAME=	cc65-2.19
CATEGORIES=	cross lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=cc65/}
GITHUB_PROJECT=	cc65
GITHUB_TAG=	V${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cc65.github.io/
COMMENT=	C cross compiler for 6502 target systems
LICENSE=	zlib

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_TOOLS+=	gmake
REPLACE_PERL=	util/ca65html

MAKE_FLAGS+=	BUILD_ID=${PKGVERSION}

INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
