# $NetBSD: Makefile,v 1.1 2022/01/11 15:21:04 fcambus Exp $

DISTNAME=	pax-utils-1.3.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=gentoo/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://wiki.gentoo.org/wiki/Hardened/PaX_Utilities
COMMENT=	ELF related utils for ELF 32/64 binaries
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		bash:run gmake
REPLACE_BASH+=		symtree.sh
REPLACE_PYTHON+=	lddtree.py

BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
DEPENDS+=	${PYPKGPREFIX}-pyelftools-[0-9]*:../../devel/py-pyelftools

MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX} MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

post-build:
	${RUN}cd ${WRKSRC}/man && ${GMAKE}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
