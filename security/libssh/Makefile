# $NetBSD: Makefile,v 1.21 2016/02/23 15:49:42 wiz Exp $
#
# history: upstream renamed 0.11 to 0.1.1;
# we have to use the old-style convention so that version compares work.
#
VER=			0.7.3
DISTNAME=		libssh-${VER}
PKGNAME=		libssh-0.73
CATEGORIES=		security
MASTER_SITES=		https://red.libssh.org/attachments/download/195/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://www.libssh.org/
COMMENT=		SSHv2+v1 protocol library
LICENSE=		2-clause-bsd

DIST_SUBDIR=		security

USE_CMAKE=		yes
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=	libssh.pc.in
TEST_TARGET=		check

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
