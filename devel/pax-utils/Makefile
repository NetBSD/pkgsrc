# $NetBSD: Makefile,v 1.9 2023/02/09 17:14:35 fcambus Exp $

DISTNAME=	pax-utils-1.3.7
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://dev.gentoo.org/~sam/distfiles/app-misc/pax-utils/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://wiki.gentoo.org/wiki/Hardened/PaX_Utilities
COMMENT=	ELF related utils for ELF 32/64 binaries
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		bash:run gmake gsed
REPLACE_BASH+=		symtree.sh
REPLACE_BASH+=		lddtree.sh

MESON_ARGS=	-Dlddtree_implementation=sh

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
