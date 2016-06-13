# $NetBSD: Makefile,v 1.9 2016/06/13 01:51:04 kamil Exp $

.include "Makefile.common"

PKGREVISION=	2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Lightweight multi-platform, multi-architecture disassembly framework
LICENSE=	modified-bsd

PKGCONFIG_OVERRIDE+=		capstone.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build
USE_TOOLS+=			gmake
# succeeds after 'make install'
TEST_TARGET=			check

# Don't use FreeBSD/DragonFly specific paths
ALL_ENV+=	USE_GENERIC_LIBDATADIR=yes

.include "../../mk/bsd.pkg.mk"
