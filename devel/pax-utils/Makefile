# $NetBSD: Makefile,v 1.10 2023/08/28 15:09:32 fcambus Exp $

DISTNAME=	pax-utils-1.3.7
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://dev.gentoo.org/~sam/distfiles/app-misc/pax-utils/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gentoo.org/wiki/Hardened/PaX_Utilities
COMMENT=	ELF related utils for ELF 32/64 binaries
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		bash:run gmake gsed
REPLACE_BASH+=		symtree.sh
REPLACE_BASH+=		lddtree.sh

MESON_ARGS=	-Dlddtree_implementation=sh

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
