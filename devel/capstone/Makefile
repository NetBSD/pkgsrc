# $NetBSD: Makefile,v 1.11 2018/11/12 14:40:21 jperkin Exp $

.include "Makefile.common"

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

CTF_SUPPORTED=	no # https://smartos.org/bugview/OS-6510

.include "../../mk/bsd.pkg.mk"
