# $NetBSD: Makefile,v 1.1 2026/10/02 01:08:40 charlotte Exp $

DISTNAME=	0.26.0
PKGNAME=	harec-${DISTNAME}
CATEGORIES=	lang
MASTER_SITES=	https://git.sr.ht/~sircmpwn/harec/archive/
DIST_SUBDIR=	harec

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://harelang.org/
COMMENT=	Compiler for the Hare language
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/harec-${DISTNAME}

TOOL_DEPENDS+=	binutils>=2.41:../../devel/binutils
DEPENDS+=	qbe>=1.2:../../lang/qbe

TEST_TARGET=		check
MAKE_FLAGS+=		LD=gld
INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}

INSTALLATION_DIRS+=	bin

pre-configure:
	cp ${WRKSRC}/configs/${OPSYS:tl}.mk ${WRKSRC}/config.mk

.include "../../mk/bsd.pkg.mk"
