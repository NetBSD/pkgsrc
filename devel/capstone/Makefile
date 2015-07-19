# $NetBSD: Makefile,v 1.6 2015/07/19 14:49:44 kamil Exp $

DISTNAME=	capstone-3.0.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=aquynh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.capstone-engine.org/
COMMENT=	Lightweight multi-platform, multi-architecture disassembly framework
LICENSE=	modified-bsd

PKGCONFIG_OVERRIDE+=	capstone.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build
USE_TOOLS+=	gmake
# succeeds after 'make install'
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
