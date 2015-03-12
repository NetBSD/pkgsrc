# $NetBSD: Makefile,v 1.3 2015/03/12 00:27:07 mef Exp $

DISTNAME=	capstone-3.0.2
CATEGORIES=	devel
MASTER_SITES=	http://www.capstone-engine.org/download/${PKGVERSION}/
EXTRACT_SUFX=	.tgz

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
