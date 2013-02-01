# $NetBSD: Makefile,v 1.12 2013/02/01 13:33:49 is Exp $
#

# history: upstream renamed 0.11 to 0.1;
# we have to use the old-style convention so that version compares work.
# 
DISTNAME=		libssh-0.5.4
PKGNAME=		libssh-0.54
CATEGORIES=		security
MASTER_SITES=		https://red.libssh.org/attachments/download/41/

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://www.libssh.org/
COMMENT=		SSHv2 and SSHv1 protocol
LICENSE=		2-clause-bsd

DIST_SUBDIR=		security

.include "../../mk/bsd.prefs.mk"

# ftp: Unsupported URL scheme `https'
FETCH_USING=		curl

USE_CMAKE=		yes
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=	libssh.pc.in
TEST_TARGET=		check

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
