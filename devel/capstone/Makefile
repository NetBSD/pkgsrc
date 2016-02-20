# $NetBSD: Makefile,v 1.8 2016/02/20 11:40:30 jperkin Exp $

DISTNAME=	capstone-3.0.4
PKGREVISION=	1
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

ALL_ENV+=	USE_GENERIC_LIBDATADIR=yes

.include "../../mk/bsd.pkg.mk"
