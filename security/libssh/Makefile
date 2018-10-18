# $NetBSD: Makefile,v 1.23.18.1 2018/10/18 13:02:36 bsiegert Exp $
#
# history: upstream renamed 0.11 to 0.1.1;
# we have to use the old-style convention so that version compares work.
#
VER=			0.7.6
DISTNAME=		libssh-${VER}
PKGNAME=		libssh-0.76
CATEGORIES=		security
MASTER_SITES=		https://www.libssh.org/files/0.7/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://www.libssh.org/
COMMENT=		SSHv2+v1 protocol library
LICENSE=		2-clause-bsd

DIST_SUBDIR=		security

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
CMAKE_ARGS+=		WITH_TESTING=yes

PKGCONFIG_OVERRIDE+=	libssh.pc.in
TEST_TARGET=		check

.include "options.mk"

.include "../../devel/argp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
