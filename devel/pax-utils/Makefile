# $NetBSD: Makefile,v 1.8 2023/01/31 14:44:50 fcambus Exp $

DISTNAME=	pax-utils-1.3.7
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://dev.gentoo.org/~sam/distfiles/app-misc/pax-utils/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://wiki.gentoo.org/wiki/Hardened/PaX_Utilities
COMMENT=	ELF related utils for ELF 32/64 binaries
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		bash:run gmake gsed
REPLACE_BASH+=		symtree.sh
REPLACE_PYTHON+=	lddtree.py

DEPENDS+=	${PYPKGPREFIX}-pyelftools-[0-9]*:../../devel/py-pyelftools

.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
