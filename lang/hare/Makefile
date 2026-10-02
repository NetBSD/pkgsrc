# $NetBSD: Makefile,v 1.1 2026/10/02 01:11:59 charlotte Exp $

DISTNAME=	0.26.0.1
PKGNAME=	hare-${DISTNAME}
CATEGORIES=	lang
MASTER_SITES=	https://git.sr.ht/~sircmpwn/hare/archive/
DIST_SUBDIR=	hare

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://harelang.org/
COMMENT=	The Hare programming language
LICENSE=	gnu-gpl-v3 AND mpl-2.0

WRKSRC=		${WRKDIR}/hare-${DISTNAME}

USE_TOOLS+=	gmake

TOOL_DEPENDS+=	binutils>=2.41:../../devel/binutils
TOOL_DEPENDS+=	scdoc>=1.10.0:../../textproc/scdoc
DEPENDS+=	harec>=0.26.0:../../lang/harec

TEST_TARGET=		check
MAKE_FLAGS+=		LD=gld
MAKE_FLAGS+=		OPSYS=${OPSYS:tl}

pre-configure:
	cp ${FILESDIR}/config.mk ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
